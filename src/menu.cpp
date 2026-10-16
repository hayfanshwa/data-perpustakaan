#include "menu.h"

#include "berkas.h"

#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <string>

void jalankanMenu(KumpulanBuku& koleksi, const std::string& namaBerkas) {
    std::string masukan;
    bool selesai = false;

    while (!selesai) {
        std::cout << "\n=== PENDATAAN BUKU PERPUSTAKAAN ===\n"
                  << "1. Tambah buku\n"
                  << "2. Tampilkan semua buku\n"
                  << "3. Cari buku\n"
                  << "4. Urutkan buku\n"
                  << "5. Ubah buku\n"
                  << "6. Hapus buku\n"
                  << "7. Statistik koleksi\n"
                  << "8. Info memori\n"
                  << "0. Simpan dan keluar\n"
                  << "Pilihan: ";

        if (!std::getline(std::cin, masukan)) {
            std::cout << "\nInput berakhir. Menyimpan data sebelum keluar.\n";
            selesai = true;
            continue;
        }
        errno = 0;
        char* akhir = nullptr;
        const long pilihan = std::strtol(masukan.c_str(), &akhir, 10);
        if (errno == ERANGE || akhir == masukan.c_str() || *akhir != '\0') {
            std::cout << "Masukan harus berupa angka menu.\n";
            continue;
        }

        switch (pilihan) {
            case 1:
                tambahBuku(koleksi);
                if (simpanBuku(namaBerkas, koleksi)) std::cout << "Perubahan tersimpan.\n";
                break;
            case 2: tampilkanBuku(koleksi); break;
            case 3: cariBuku(koleksi); break;
            case 4:
                urutkanBuku(koleksi);
                if (simpanBuku(namaBerkas, koleksi)) std::cout << "Perubahan tersimpan.\n";
                break;
            case 5:
                ubahBuku(koleksi);
                if (simpanBuku(namaBerkas, koleksi)) std::cout << "Perubahan tersimpan.\n";
                break;
            case 6:
                hapusBuku(koleksi);
                if (simpanBuku(namaBerkas, koleksi)) std::cout << "Perubahan tersimpan.\n";
                break;
            case 7: tampilkanStatistik(koleksi); break;
            case 8: tampilkanInfoMemori(); break;
            case 0:
                if (simpanBuku(namaBerkas, koleksi)) {
                    std::cout << "Data tersimpan.\n";
                }
                selesai = true;
                break;
            default: std::cout << "Pilihan tidak tersedia.\n";
        }
    }
}