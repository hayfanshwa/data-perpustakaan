#include "buku.h"

#include <algorithm>
#include <cerrno>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

namespace {
std::string keHurufKecil(std::string teks) {
    std::transform(teks.begin(), teks.end(), teks.begin(), [](unsigned char karakter) {
        return static_cast<char>(std::tolower(karakter));
    });
    return teks;
}

std::string keHurufBesar(std::string teks) {
    std::transform(teks.begin(), teks.end(), teks.begin(), [](unsigned char karakter) {
        return static_cast<char>(std::toupper(karakter));
    });
    return teks;
}

bool bacaTeks(const std::string& label, std::string& nilai) {
    std::cout << label;
    return static_cast<bool>(std::getline(std::cin, nilai));
}

bool parseAngka(const std::string& teks, unsigned int minimum,
                unsigned int maksimum, unsigned int& hasil) {
    if (teks.empty()) {
        return false;
    }
    errno = 0;
    char* akhir = nullptr;
    const unsigned long angka = std::strtoul(teks.c_str(), &akhir, 10);
    if (errno == ERANGE || akhir == teks.c_str() || *akhir != '\0' ||
        angka < minimum || angka > maksimum) {
        return false;
    }
    hasil = static_cast<unsigned int>(angka);
    return true;
}

bool bacaAngka(const std::string& label, unsigned int minimum,
               unsigned int maksimum, unsigned int& hasil) {
    std::string teks;
    while (bacaTeks(label, teks)) {
        if (parseAngka(teks, minimum, maksimum, hasil)) {
            return true;
        }
        std::cout << "Masukkan angka " << minimum << " sampai " << maksimum << ".\n";
    }
    return false;
}

bool salinTeks(char* tujuan, std::size_t kapasitas, const std::string& sumber) {
    if (sumber.empty() || sumber.size() >= kapasitas ||
        sumber.find('|') != std::string::npos) {
        return false;
    }
    std::memcpy(tujuan, sumber.c_str(), sumber.size() + 1);
    return true;
}

bool isiDataBuku(Buku& buku, std::string kode, const std::string& judul,
                 const std::string& penulis, const std::string& penerbit,
                 unsigned int tahun, unsigned int halaman, unsigned int stok) {
    kode = keHurufBesar(kode);
    if (!salinTeks(buku.kode, sizeof(buku.kode), kode) ||
        !salinTeks(buku.judul, sizeof(buku.judul), judul) ||
        !salinTeks(buku.detail.penulis, sizeof(buku.detail.penulis), penulis) ||
        !salinTeks(buku.detail.penerbit, sizeof(buku.detail.penerbit), penerbit) ||
        tahun < 1450 || tahun > 2100 || halaman < 1 || halaman > 5000 || stok > 255) {
        return false;
    }
    buku.detail.tahunTerbit = static_cast<std::uint16_t>(tahun);
    buku.detail.jumlahHalaman = static_cast<std::uint16_t>(halaman);
    buku.stok = static_cast<std::uint8_t>(stok);
    return true;
}

bool inputDataBuku(Buku& buku) {
    std::string kode;
    std::string judul;
    std::string penulis;
    std::string penerbit;
    unsigned int tahun = 0;
    unsigned int halaman = 0;
    unsigned int stok = 0;

    if (!bacaTeks("Kode: ", kode) || !bacaTeks("Judul: ", judul) ||
        !bacaTeks("Penulis: ", penulis) || !bacaTeks("Penerbit: ", penerbit) ||
        !bacaAngka("Tahun terbit (1450-2100): ", 1450, 2100, tahun) ||
        !bacaAngka("Jumlah halaman (1-5000): ", 1, 5000, halaman) ||
        !bacaAngka("Stok (0-255): ", 0, 255, stok)) {
        return false;
    }

    if (!isiDataBuku(buku, kode, judul, penulis, penerbit, tahun, halaman, stok)) {
        std::cout << "Data tidak valid. Pastikan teks tidak kosong, panjangnya sesuai, "
                     "dan tidak mengandung karakter '|'.\n";
        return false;
    }
    return true;
}

int cariIndeksKode(const KumpulanBuku& koleksi, const std::string& kode) {
    const std::string target = keHurufBesar(kode);
    for (std::size_t indeks = 0; indeks < koleksi.jumlah; ++indeks) {
        if (keHurufBesar(koleksi.data[indeks].kode) == target) {
            return static_cast<int>(indeks);
        }
    }
    return -1;
}

std::string potong(const char* teks, std::size_t lebar) {
    std::string hasil(teks);
    if (hasil.size() > lebar) {
        hasil.resize(lebar - 2);
        hasil += "..";
    }
    return hasil;
}

void cetakBaris(const Buku& buku) {
    std::cout << std::left << std::setw(9) << potong(buku.kode, 8)
              << std::setw(25) << potong(buku.judul, 24)
              << std::setw(20) << potong(buku.detail.penulis, 19)
              << std::setw(21) << potong(buku.detail.penerbit, 20)
              << std::right << std::setw(6) << buku.detail.tahunTerbit
              << std::setw(8) << buku.detail.jumlahHalaman
              << std::setw(6) << static_cast<unsigned int>(buku.stok) << '\n';
}

}

void tambahBuku(KumpulanBuku& koleksi) {
    if (koleksi.jumlah >= KAPASITAS_BUKU) {
        std::cout << "Kapasitas koleksi penuh.\n";
        return;
    }
    Buku buku{};
    if (!inputDataBuku(buku)) {
        std::cout << "Penambahan dibatalkan.\n";
        return;
    }
    if (kodeSudahAda(koleksi, buku.kode)) {
        std::cout << "Kode buku sudah digunakan.\n";
        return;
    }
    koleksi.data[koleksi.jumlah++] = buku;
    std::cout << "Buku berhasil ditambahkan.\n";
}

void tampilkanBuku(const KumpulanBuku& koleksi) {
    if (koleksi.jumlah == 0) {
        std::cout << "Belum ada data buku.\n";
        return;
    }
    std::cout << std::left << std::setw(9) << "KODE" << std::setw(25) << "JUDUL"
              << std::setw(20) << "PENULIS" << std::setw(21) << "PENERBIT"
              << std::right << std::setw(6) << "TAHUN" << std::setw(8) << "HALAMAN"
              << std::setw(6) << "STOK" << '\n';
    std::cout << std::string(95, '-') << '\n';
    for (std::size_t indeks = 0; indeks < koleksi.jumlah; ++indeks) {
        cetakBaris(koleksi.data[indeks]);
    }
}

void cariBuku(const KumpulanBuku& koleksi) {
    std::string kataKunci;
    if (!bacaTeks("Masukkan kata kunci judul/penulis/kode: ", kataKunci)) {
        return;
    }
    const std::string target = keHurufKecil(kataKunci);
    bool ditemukan = false;
    for (std::size_t indeks = 0; indeks < koleksi.jumlah; ++indeks) {
        const Buku& buku = koleksi.data[indeks];
        const std::string gabungan = keHurufKecil(
            std::string(buku.kode) + " " + buku.judul + " " +
            buku.detail.penulis + " " + buku.detail.penerbit);
        if (gabungan.find(target) != std::string::npos) {
            if (!ditemukan) {
                std::cout << std::left << std::setw(9) << "KODE" << std::setw(25) << "JUDUL"
                          << std::setw(20) << "PENULIS" << std::setw(21) << "PENERBIT"
                          << std::right << std::setw(6) << "TAHUN" << std::setw(8) << "HALAMAN"
                          << std::setw(6) << "STOK" << '\n';
            }
            cetakBaris(buku);
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        std::cout << "Buku tidak ditemukan.\n";
    }
}

void urutkanBuku(KumpulanBuku& koleksi) {
    for (std::size_t batas = koleksi.jumlah; batas > 1; --batas) {
        for (std::size_t indeks = 0; indeks + 1 < batas; ++indeks) {
            if (keHurufKecil(koleksi.data[indeks].judul) >
                keHurufKecil(koleksi.data[indeks + 1].judul)) {
                std::swap(koleksi.data[indeks], koleksi.data[indeks + 1]);
            }
        }
    }
    std::cout << "Buku diurutkan berdasarkan judul (bubble sort).\n";
}

void ubahBuku(KumpulanBuku& koleksi) {
    std::string kode;
    if (!bacaTeks("Masukkan kode buku yang akan diubah: ", kode)) {
        return;
    }
    const int indeks = cariIndeksKode(koleksi, kode);
    if (indeks < 0) {
        std::cout << "Kode buku tidak ditemukan.\n";
        return;
    }
    Buku bukuBaru{};
    if (!inputDataBuku(bukuBaru)) {
        std::cout << "Perubahan dibatalkan.\n";
        return;
    }
    if (kodeSudahAda(koleksi, bukuBaru.kode) &&
        keHurufBesar(bukuBaru.kode) != keHurufBesar(koleksi.data[indeks].kode)) {
        std::cout << "Kode buku sudah digunakan oleh data lain.\n";
        return;
    }
    koleksi.data[indeks] = bukuBaru;
    std::cout << "Data buku berhasil diubah.\n";
}

void hapusBuku(KumpulanBuku& koleksi) {
    std::string kode;
    if (!bacaTeks("Masukkan kode buku yang akan dihapus: ", kode)) {
        return;
    }
    const int indeks = cariIndeksKode(koleksi, kode);
    if (indeks < 0) {
        std::cout << "Kode buku tidak ditemukan.\n";
        return;
    }
    for (std::size_t posisi = static_cast<std::size_t>(indeks);
         posisi + 1 < koleksi.jumlah; ++posisi) {
        koleksi.data[posisi] = koleksi.data[posisi + 1];
    }
    --koleksi.jumlah;
    std::cout << "Buku berhasil dihapus.\n";
}

void tampilkanStatistik(const KumpulanBuku& koleksi) {
    if (koleksi.jumlah == 0) {
        std::cout << "Belum ada data untuk direkap.\n";
        return;
    }
    std::uint64_t totalStok = 0;
    std::uint8_t stokMinimum = std::numeric_limits<std::uint8_t>::max();
    std::uint8_t stokMaksimum = 0;
    for (std::size_t indeks = 0; indeks < koleksi.jumlah; ++indeks) {
        const std::uint8_t stok = koleksi.data[indeks].stok;
        totalStok += stok;
        stokMinimum = std::min(stokMinimum, stok);
        stokMaksimum = std::max(stokMaksimum, stok);
    }
    std::cout << "Jumlah judul       : " << koleksi.jumlah << '\n'
              << "Total stok eksemplar: " << totalStok << '\n'
              << "Rata-rata stok     : "
              << std::fixed << std::setprecision(2)
              << static_cast<double>(totalStok) / koleksi.jumlah << '\n'
              << "Stok minimum       : " << static_cast<unsigned int>(stokMinimum) << '\n'
              << "Stok maksimum      : " << static_cast<unsigned int>(stokMaksimum) << '\n';
}

void tampilkanInfoMemori() {
    std::cout << "sizeof(DetailBuku)       : " << sizeof(DetailBuku) << " byte\n"
              << "sizeof(Buku)             : " << sizeof(Buku) << " byte\n"
              << "sizeof(KumpulanBuku)     : " << sizeof(KumpulanBuku) << " byte\n"
              << "Ukuran array data buku   : "
              << sizeof(Buku) * KAPASITAS_BUKU << " byte\n";
}

bool kodeSudahAda(const KumpulanBuku& koleksi, const char* kode) {
    const std::string target = keHurufBesar(kode);
    for (std::size_t indeks = 0; indeks < koleksi.jumlah; ++indeks) {
        if (keHurufBesar(koleksi.data[indeks].kode) == target) {
            return true;
        }
    }
    return false;
}