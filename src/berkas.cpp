#include "berkas.h"

#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace {
bool spasi(char c) {
    return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}

string trim(const string& teks) {
    size_t awal = 0;
    size_t akhir = teks.size();
    while (awal < akhir && spasi(teks[awal])) {
        ++awal;
    }
    while (akhir > awal && spasi(teks[akhir - 1])) {
        --akhir;
    }
    return teks.substr(awal, akhir - awal);
}

vector<string> pisahkanKolom(const string& baris) {
    vector<string> kolom;
    string sel;
    for (size_t indeks = 0; indeks < baris.size(); ++indeks) {
        if (baris[indeks] == '|') {
            kolom.push_back(trim(sel));
            sel = "";
        } else {
            sel += baris[indeks];
        }
    }
    kolom.push_back(trim(sel));
    return kolom;
}

bool angkaValid(const string& teks, unsigned int minimum,
                unsigned int maksimum, unsigned int& hasil) {
    if (teks.empty()) {
        return false;
    }
    errno = 0;
    char* akhir = nullptr;
    const unsigned long angka = strtoul(teks.c_str(), &akhir, 10);
    if (errno == ERANGE || akhir == teks.c_str() || *akhir != '\0' ||
        angka < minimum || angka > maksimum) {
        return false;
    }
    hasil = static_cast<unsigned int>(angka);
    return true;
}

bool salinField(char* tujuan, size_t kapasitas, const string& nilai) {
    if (nilai.empty() || nilai.size() >= kapasitas) {
        return false;
    }
    memcpy(tujuan, nilai.c_str(), nilai.size() + 1);
    return true;
}

bool kodeDuplikat(const KumpulanBuku& koleksi, const char* kode) {
    for (size_t indeks = 0; indeks < koleksi.jumlah; ++indeks) {
        if (strcmp(koleksi.data[indeks].kode, kode) == 0) {
            return true;
        }
    }
    return false;
}
}

size_t bacaBuku(const string& namaBerkas, KumpulanBuku& koleksi) {
    ifstream berkas(namaBerkas);
    koleksi.jumlah = 0;
    if (!berkas) {
        cout << "Berkas " << namaBerkas
             << " belum tersedia; program dimulai dengan koleksi kosong.\n";
        return 0;
    }

    size_t barisKe = 0;
    size_t barisInvalid = 0;
    string baris;
    while (getline(berkas, baris)) {
        ++barisKe;
        if (trim(baris).empty()) {
            continue;
        }
        const vector<string> kolom = pisahkanKolom(baris);
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
            cout << "Baris " << barisKe << " dilewati: format atau nilai tidak valid.\n";
            continue;
        }

        Buku buku{};
        if (!salinField(buku.kode, sizeof(buku.kode), kolom[0]) ||
            !salinField(buku.judul, sizeof(buku.judul), kolom[1]) ||
            !salinField(buku.detail.penulis, sizeof(buku.detail.penulis), kolom[2]) ||
            !salinField(buku.detail.penerbit, sizeof(buku.detail.penerbit), kolom[3])) {
            ++barisInvalid;
            cout << "Baris " << barisKe << " dilewati: ada kolom kosong.\n";
            continue;
        }
        if (kodeDuplikat(koleksi, buku.kode)) {
            ++barisInvalid;
            cout << "Baris " << barisKe << " dilewati: kode buku duplikat.\n";
            continue;
        }
        if (koleksi.jumlah >= KAPASITAS_BUKU) {
            ++barisInvalid;
            cout << "Baris " << barisKe << " dilewati: kapasitas array penuh.\n";
            continue;
        }
        buku.detail.tahunTerbit = static_cast<uint16_t>(tahun);
        buku.detail.jumlahHalaman = static_cast<uint16_t>(halaman);
        buku.stok = static_cast<uint8_t>(stok);
        koleksi.data[koleksi.jumlah++] = buku;
    }

    cout << "Data dimuat: " << koleksi.jumlah << " record valid, "
         << barisInvalid << " baris dilewati.\n";
    return koleksi.jumlah;
}

bool simpanBuku(const string& namaBerkas, const KumpulanBuku& koleksi) {
    ofstream berkas(namaBerkas);
    if (!berkas) {
        cerr << "Gagal membuka " << namaBerkas << " untuk ditulis.\n";
        return false;
    }
    berkas << "kode|judul|penulis|penerbit|tahun|halaman|stok\n";
    for (size_t indeks = 0; indeks < koleksi.jumlah; ++indeks) {
        const Buku& buku = koleksi.data[indeks];
        berkas << buku.kode << '|' << buku.judul << '|' << buku.detail.penulis << '|'
               << buku.detail.penerbit << '|' << buku.detail.tahunTerbit << '|'
               << buku.detail.jumlahHalaman << '|'
               << static_cast<unsigned int>(buku.stok) << '\n';
    }
    if (!berkas) {
        cerr << "Terjadi kesalahan saat menulis data.\n";
        return false;
    }
    return true;
}
