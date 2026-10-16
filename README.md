## Program Pendataan Buku Perpustakaan

Program konsol C++ untuk mengelola koleksi perpustakaan. Data disimpan di `data/buku.txt` dan dimuat kembali setiap program dijalankan.

### Fitur

- Tambah, tampilkan, cari, ubah, dan hapus data buku.
- Pencarian kode, judul, penulis, atau penerbit tanpa membedakan huruf kapital.
- Pengurutan judul menggunakan bubble sort.
- Statistik jumlah judul, total/rata-rata stok, stok minimum, dan maksimum.
- Info ukuran struct dan array menggunakan `sizeof`.
- Validasi input, kapasitas array tetap 100 buku, deteksi kode duplikat, dan penanganan baris data tidak valid.
- Penyimpanan otomatis setelah operasi perubahan dan saat keluar.

### Struktur

```text
Makefile
README.md
data/buku.txt
src/
  main.cpp
  buku.h
  buku.cpp
  berkas.h
  berkas.cpp
  menu.h
  menu.cpp
```

`Buku` memuat `DetailBuku` sebagai struct bersarang. Ukuran teks maksimum: kode 11 karakter, judul 59, penulis 39, dan penerbit 39. Tahun diterima pada rentang 1450-2100, halaman 1-5000, dan stok 0-255. Kapasitas 100 record memberi batas penggunaan memori tetap yang dapat dilihat melalui menu Info Memori.

### Build dan jalankan

Jalankan dari folder proyek menggunakan GNU Make dan g++:

```sh
make clean
make
make run
```

`make run` membuka menu interaktif. Pilih `0` untuk menyimpan dan keluar. Makefile menetapkan `CXX`, `CXXFLAGS` dengan `-Wall`, dependensi tiap file objek, serta target `all`, `run`, dan `clean`.

### Data uji

`data/buku.txt` memuat 20 record valid dan tiga baris invalid: jumlah kolom salah, kode duplikat, dan tahun di luar rentang. Program melanjutkan pembacaan setelah menemukan baris invalid. Saat penyimpanan berhasil, berkas ditulis ulang hanya dengan record valid; karena itu tiga baris invalid hanya ada pada data uji awal dan akan hilang setelah program menyimpan.

### Catatan UTS

Gunakan implementasi ini sebagai bahan belajar dan pastikan seluruh anggota kelompok memahami serta mampu menjelaskan kode. Naskah UTS memperingatkan konsekuensi plagiarisme untuk kode identik/berkemiripan tinggi yang terdeteksi menggunakan LLM. Buat laporan dari pengujian aktual kelompok: jangan mengarang spesifikasi compiler/OS, ukuran memori, tangkapan layar, atau kesalahan yang ditemui. Flowchart, analisis padding sebelum/sesudah optimasi, identitas kelompok, laporan PDF, dan video tetap perlu disiapkan terpisah sesuai naskah.