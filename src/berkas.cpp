#include "berkas.h"

#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace {
std::string trim(const std::string& teks) {
    const std::size_t awal = teks.find_first_not_of(" \t\r\n");
    if (awal == std::string::npos) {
        return "";
    }
    const std::size_t akhir = teks.find_last_not_of(" \t\r\n");
    return teks.substr(awal, akhir - awal + 1);
}

std::vector<std::string> pisahkanKolom(const std::string& baris) {
    std::vector<std::string> kolom;
    std::size_t awal = 0;
    while (awal <= baris.size()) {
        const std::size_t pemisah = baris.find('|', awal);
        if (pemisah == std::string::npos) {
            kolom.push_back(trim(baris.substr(awal)));
            break;
        }
        kolom.push_back(trim(baris.substr(awal, pemisah - awal)));
        awal = pemisah + 1;
    }
    return kolom;
}

bool angkaValid(const std::string& teks, unsigned int minimum,
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

bool salinField(char* tujuan, std::size_t kapasitas, const std::string& nilai) {
    if (nilai.empty() || nilai.size() >= kapasitas) {
        return false;
    }
    std::memcpy(tujuan, nilai.c_str(), nilai.size() + 1);
    return true;
}

bool kodeDuplikat(const KumpulanBuku& koleksi, const char* kode) {
    for (std::size_t indeks = 0; indeks < koleksi.jumlah; ++indeks) {
        if (std::strcmp(koleksi.data[indeks].kode, kode) == 0) {
            return true;
        }
    }
    return false;
}
}

std::size_t bacaBuku(const std::string& namaBerkas, KumpulanBuku& koleksi) {
    std::ifstream berkas(namaBerkas);
    koleksi.jumlah = 0;
    if (!berkas) {
        std::cout << "Berkas " << namaBerkas
                  << " belum tersedia; program dimulai dengan koleksi kosong.\n";
        return 0;
    }

    std::size_t barisKe = 0;
    std::size_t barisInvalid = 0;
    std::string baris;
    while (std::getline(berkas, baris)) {
        ++barisKe;
        if (trim(baris).empty()) {
            continue;
        }
        const std::vector<std::string> kolom = pisahkanKolom(baris);
        if (barisKe == 1 && !kolom.empty() && kolom[0] == "kode") {
            continue;
        }

        unsigned int tahun = 0;
        unsigned int halaman = 0;
        unsigned int stok = 0;
        if (kolom.size() != 7 ||
            kolom[0].size() >= PANJANG_KODE || kolom[1].size() >= PANJANG_JUDUL ||
            kolom[2].size() >= PANJANG_NAMA || kolom[3].size() >= PANJANG_NAMA ||
            !angkaValid(kolom[4], 1450, 2100, tahun) ||
            !angkaValid(kolom[5], 1, 5000, halaman) ||
            !angkaValid(kolom[6], 0, 255, stok)) {
            ++barisInvalid;
            std::cout << "Baris " << barisKe << " dilewati: format atau nilai tidak valid.\n";
            continue;
        }

        Buku buku{};
        if (!salinField(buku.kode, sizeof(buku.kode), kolom[0]) ||
            !salinField(buku.judul, sizeof(buku.judul), kolom[1]) ||
            !salinField(buku.detail.penulis, sizeof(buku.detail.penulis), kolom[2]) ||
            !salinField(buku.detail.penerbit, sizeof(buku.detail.penerbit), kolom[3])) {
            ++barisInvalid;
            std::cout << "Baris " << barisKe << " dilewati: ada kolom kosong.\n";
            continue;
        }
        if (kodeDuplikat(koleksi, buku.kode)) {
            ++barisInvalid;
            std::cout << "Baris " << barisKe << " dilewati: kode buku duplikat.\n";
            continue;
        }
        if (koleksi.jumlah >= KAPASITAS_BUKU) {
            ++barisInvalid;
            std::cout << "Baris " << barisKe << " dilewati: kapasitas array penuh.\n";
            continue;
        }
        buku.detail.tahunTerbit = static_cast<std::uint16_t>(tahun);
        buku.detail.jumlahHalaman = static_cast<std::uint16_t>(halaman);
        buku.stok = static_cast<std::uint8_t>(stok);
        koleksi.data[koleksi.jumlah++] = buku;
    }

    std::cout << "Data dimuat: " << koleksi.jumlah << " record valid, "
              << barisInvalid << " baris dilewati.\n";
    return koleksi.jumlah;
}

bool simpanBuku(const std::string& namaBerkas, const KumpulanBuku& koleksi) {
    std::ofstream berkas(namaBerkas, std::ios::trunc);
    if (!berkas) {
        std::cerr << "Gagal membuka " << namaBerkas << " untuk ditulis.\n";
        return false;
    }
    berkas << "kode|judul|penulis|penerbit|tahun|halaman|stok\n";
    for (std::size_t indeks = 0; indeks < koleksi.jumlah; ++indeks) {
        const Buku& buku = koleksi.data[indeks];
        berkas << buku.kode << '|' << buku.judul << '|' << buku.detail.penulis << '|'
               << buku.detail.penerbit << '|' << buku.detail.tahunTerbit << '|'
               << buku.detail.jumlahHalaman << '|'
               << static_cast<unsigned int>(buku.stok) << '\n';
    }
    if (!berkas) {
        std::cerr << "Terjadi kesalahan saat menulis data.\n";
        return false;
    }
    return true;
}