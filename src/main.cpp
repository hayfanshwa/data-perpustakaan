#include "berkas.h"
#include "menu.h"

#include <iostream>

int main() {
    KumpulanBuku koleksi{};
    const std::string namaBerkas = "data/buku.txt";

    const std::size_t jumlahTerbaca = bacaBuku(namaBerkas, koleksi);
    std::cout << "Program Pendataan Buku Perpustakaan siap. Data terbaca: "
              << jumlahTerbaca << "\n";
    jalankanMenu(koleksi, namaBerkas);
    return 0;
}