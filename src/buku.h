#ifndef BUKU_H
#define BUKU_H

#include <cstddef>
#include <cstdint>

const std::size_t KAPASITAS_BUKU = 100;
const std::size_t PANJANG_KODE = 12;
const std::size_t PANJANG_JUDUL = 60;
const std::size_t PANJANG_NAMA = 40;

struct DetailBuku {
    char penulis[PANJANG_NAMA];
    char penerbit[PANJANG_NAMA];
    std::uint16_t tahunTerbit;
    std::uint16_t jumlahHalaman;
};

struct Buku {
    char kode[PANJANG_KODE];
    char judul[PANJANG_JUDUL];
    DetailBuku detail;
    std::uint8_t stok;
};

struct KumpulanBuku {
    Buku data[KAPASITAS_BUKU];
    std::size_t jumlah;
};

void tambahBuku(KumpulanBuku& koleksi);
void tampilkanBuku(const KumpulanBuku& koleksi);
void cariBuku(const KumpulanBuku& koleksi);
void urutkanBuku(KumpulanBuku& koleksi);
void ubahBuku(KumpulanBuku& koleksi);
void hapusBuku(KumpulanBuku& koleksi);
void tampilkanStatistik(const KumpulanBuku& koleksi);
void tampilkanInfoMemori();
bool kodeSudahAda(const KumpulanBuku& koleksi, const char* kode);

#endif