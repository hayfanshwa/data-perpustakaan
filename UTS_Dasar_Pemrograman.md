## KEMENTERIAN PENDIDIKAN TINGGI, SAINS, DAN TEKNOLOGI

## UNIVERSITAS NEGERI SURABAYA

## FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM PRODI S1 KECERDASAN ARTIFISIAL

Kampus Ketintang, Jalan Ketintang, Gedung E2, Surabaya 60231

Laman: https://ai.unesa.ac.id, Email: ai@unesa.ac.id [URL 🔗](mailto:ai@unesa.ac.id)

## NASKAH UJIAN TENGAH SEMESTER GASAL TAHUN AKADEMIK 2026/2027

Mata Kuliah

Dosen

Program/ Kelas

Waktu

Sifat

## Petunjuk Pengerjaan :

- Setiap kelompok terdiri atas minimal 2 dan maksimal 3 mahasiswa.

- Proyek dikerjakan dalam kurun waktu 7 hari sejak naskah soal diterbitkan. Seluruh luaran (kode program, laporan, dan video) wajib dikumpulkan dalam rentang waktu tersebut.

- Tema proyek ditentukan secara bebas oleh kelompok, tidak boleh sama dengan kelompok lain.

- Kode program yang identik atau memiliki kemiripan tinggi dengan kelompok lain serta terdeteksi menggunakan LLM dinyatakan sebagai plagiarisme dan memperoleh nilai 0 bagi seluruh kelompok yang terlibat.

- Penilaian bersifat kelompok dan mengacu pada rubrik penilaian yang tercantum pada naskah ini.

: Dasar Pemrograman

: Harmon Prayogi, M.Sc.

: S1 Kecerdasan Artifisial / 2026

: Minggu ke-8

: Take Home


## FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM KEMENTERIAN PENDIDIKAN TINGGI, SAINS, UNIVERSITAS NEGERI SURABAYA DAN TEKNOLOGI

PRODI S1 KECERDASAN ARTIFISIAL

Kampus Ketintang, Jalan Ketintang, Gedung E2, Surabaya 60231

Laman: https://ai.unesa.ac.id, Email: ai@unesa.ac.id [URL 🔗](mailto:ai@unesa.ac.id)

## SOAL

## Proyek Sistem Pengelolaan Data Berbasis Berkas Menggunakan Bahasa C++

Rancang dan implementasikan sebuah program konsol dalam bahasa C++ untuk mengelola data pada suatu domain permasalahan yang dipilih oleh kelompok, misalnya pengelolaan inventaris, pencatatan transaksi, rekapitulasi kegiatan, atau domain lain yang relevan. Program menyimpan data secara permanen dalam berkas teks, disusun secara modular menggunakan header file, dan dikompilasi menggunakan Makefile. Proyek ini mencakup seluruh materi yang telah dipelajari, yaitu percabangan, perulangan, array, fungsi, string, struct, file I/O, header file, dan makefile.

## 1. Ketentuan Teknis Program

- 1. Struct dan array. Program menggunakan minimal 2 struct, salah satunya memuat struct lain atau array sebagai anggotanya. Data disimpan dalam array of struct berkapasitas tetap yang ukurannya dijustifikasi dalam laporan.

- 2. Fitur wajib. Program menyediakan menu interaktif dengan fitur berikut:

- a. menambah data baru dengan validasi masukan;

- b. menampilkan seluruh data dalam format tabel yang rapi;

- c. mencari data berdasarkan minimal 1 kriteria;

- d. mengurutkan data menggunakan algoritma pengurutan yang diimplementasikan sendiri (misalnya bubble sort, selection sort, atau insertion sort);

- e. mengubah atau menghapus data;

- f. menampilkan statistik atau rekapitulasi data (misalnya total, rata-rata, nilai maksimum, atau minimum);

- g. menampilkan menu Info Memori yang mencetak hasil sizeof setiap struct dan total memori array data.

- 3. Pengolahan string. Program memuat minimal 1 fitur pengolahan string, misalnya pencarian tanpa membedakan huruf kapital, validasi format kode, atau pemformatan nama.

- 4. File I/O. Program membaca data dari berkas teks saat dijalankan dan menyimpan perubahan data ke berkas. Berkas data awal memuat minimal 20 record, termasuk minimal 3 baris tidak valid (format salah, nilai di luar rentang, atau data duplikat). Program harus menangani baris tidak valid tersebut tanpa berhenti secara tidak normal.

- 5. Modularisasi. Program disusun dalam beberapa file sumber dan header, minimal terdiri atas main.cpp serta pasangan file .h dan .cpp untuk pengelolaan data, operasi berkas, dan tampilan/menu. Struct dan array dilewatkan ke fungsi menggunakan referensi.


KEMENTERIAN PENDIDIKAN TINGGI, SAINS,

DAN TEKNOLOGI

UNIVERSITAS NEGERI SURABAYA

FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM

PRODI S1 KECERDASAN ARTIFISIAL

Kampus Ketintang, Jalan Ketintang, Gedung E2, Surabaya 60231

Laman: https://ai.unesa.ac.id, Email: ai@unesa.ac.id [URL 🔗](mailto:ai@unesa.ac.id)

- 6. Makefile. Program dikompilasi menggunakan Makefile yang memuat variabel CXX dan CXXFLAGS (minimal dengan opsi -Wall), aturan kompilasi setiap file objek beserta dependensinya, serta target all, run, dan clean.

- 7. Efisiensi memori. Tipe data setiap anggota struct dipilih sesuai rentang nilai yang mungkin, urutan anggota struct disusun untuk meminimalkan padding, dan tidak terjadi overflow. Efisiensi tidak boleh mengorbankan kebenaran luaran program.

- 2. Laporan

Laporan disusun dalam format PDF dengan sistematika sebagai berikut:

- 1. Halaman judul dan identitas anggota kelompok (Nama, NIM, dan kelas).

- 2. Flowchart alur utama program dan minimal 2 fungsi utama.

- 3. Struktur file proyek dan penjelasan peran setiap file.

- 4. Penjelasan kode program per blok atau fungsi, mencakup tujuan, cara kerja, serta justifikasi pemilihan sintaks.

- 5. Penjelasan Makefile, meliputi target, dependensi, variabel, serta prosedur kompilasi dan eksekusi program.

- 6. Analisis penggunaan memori dalam bentuk tabel yang memuat setiap anggota struct (tipe data, rentang nilai, ukuran dalam byte, dan justifikasi), perbandingan sizeof struct sebelum dan sesudah optimasi, serta spesifikasi kompiler dan sistem operasi yang digunakan.

- 7. Catatan kesalahan program, memuat minimal 3 kesalahan aktual yang ditemui beserta gejala atau pesan galat, penyebab, dan cara perbaikannya.

- 8. Hasil pengujian program dengan tangkapan layar.

- 9. Tautan folder Google Drive berisi laporan, kode lengkap, dan video penjelasan.

- 3. Video Penjelasan

- 1. Video berdurasi 15–25 menit, diunggah ke Google Drive dan tautannya dicantumkan dalam laporan.

- 2. Seluruh anggota kelompok wajib tampil (wajah atau suara) dengan tampilan layar yang terlihat jelas.

- 3. Video memuat: (a) penjelasan bagian kode oleh masing-masing anggota; (b) eksekusi program menggunakan file data uji yang diberikan tanpa mengubah kode; (c) pengerjaan dan penjelasan modifikasi program yang diminta; serta (d) demonstrasi make clean dan make, kemudian perubahan pada satu file .cpp disertai penjelasan alasan hanya file tersebut yang dikompilasi ulang.


KEMENTERIAN PENDIDIKAN TINGGI, SAINS,

FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM

- 4. Pengumpulan

Format nama folder: UTS_DasPro_NamaKetuaKelompok_Kelas. Folder Google Drive minimal

berisi folder src/ (file .cpp dan .h), Makefile, folder data/, dan laporan dalam format PDF. Akses

folder Google Drive hanya untuk anggota kelompok dan harmonprayogi@unesa.ac.id, [URL 🔗](mailto:harmonprayogi@unesa.ac.id)


## KEMENTERIAN PENDIDIKAN TINGGI, SAINS, DAN TEKNOLOGI

## UNIVERSITAS NEGERI SURABAYA

## FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM PRODI S1 KECERDASAN ARTIFISIAL

Kampus Ketintang, Jalan Ketintang, Gedung E2, Surabaya 60231

Laman: https://ai.unesa.ac.id, Email: ai@unesa.ac.id [URL 🔗](mailto:ai@unesa.ac.id)

## RUBRIK PENILAIAN

## Komponen dan Bobot Penilaian

Penilaian proyek terdiri atas tiga komponen dengan total 100 poin. Komponen video penjelasan memperoleh bobot terbesar karena merupakan bukti utama pemahaman kelompok terhadap program yang dikembangkan. Seluruh penilaian bersifat kelompok.

| Komponen | Cakupan Penilaian | Bobot |
| --- | --- | --- |
| A. Kode Program | Fungsionalitas, perancangan struct, modularisasi, file I/O, efisiensi memori, dan kualitas penulisan kode | 35 |
| B. Laporan | flowchart, penjelasan kode, makefile, analisis memori, dan catatan kesalahan program | 25 |
| C. Video Penjelasan | Penjelasan kode, pengujian dengan data uji, modifikasi program, demonstrasi makefile, dan kualitas penyajian | 40 |
| Total |   | 100 |

## Skala Penilaian

Setiap kriteria dinilai menggunakan skala 0–4. Skor yang diperoleh kemudian dikonversi secara proporsional terhadap bobot kriteria yang bersangkutan.

| Skor | Kategori | Deskripsi Umum |
| --- | --- | --- |
| 4 | Sangat Baik | Seluruh ketentuan terpenuhi, implementasi benar, dan disertai justifikasi yang tepat |
| 3 | Baik | Sebagian besar ketentuan terpenuhi dengan kekurangan minor |
| 2 | Cukup | Sebagian ketentuan terpenuhi dengan kekurangan yang signifikan |
| 1 | Kurang | Terdapat upaya pengerjaan, tetapi sebagian besar ketentuan tidak terpenuhi |
| 0 | Tidak Dinilai | Tidak dikerjakan atau tidak dapat dievaluasi |

Nilai kriteria = (skor ÷ 4) × bobot kriteria. Sebagai ilustrasi, kriteria dengan bobot 10 dan skor 3 menghasilkan nilai 3/4 × 10 = 7,5 poin.


## KEMENTERIAN PENDIDIKAN TINGGI, SAINS, DAN TEKNOLOGI

UNIVERSITAS NEGERI SURABAYA

## FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM PRODI S1 KECERDASAN ARTIFISIAL

Kampus Ketintang, Jalan Ketintang, Gedung E2, Surabaya 60231

Laman: https://ai.unesa.ac.id, Email: ai@unesa.ac.id [URL 🔗](mailto:ai@unesa.ac.id)

## A. Kode Program (35 poin)

Kode program dievaluasi melalui proses kompilasi menggunakan make dan eksekusi program, tidak hanya melalui pembacaan kode sumber.

| Kriteria | Bobot | 4 – Sangat Baik | 3 – Baik | 2 – Cukup | 1 – Kurang |
| --- | --- | --- | --- | --- | --- |
| A1. Fungsionalitas fitur wajib | 10 | Seluruh fitur wajib berfungsi dengan benar, termasuk pada kasus batas (data kosong, kapasitas penuh, dan data tidak ditemukan) | Seluruh fitur tersedia, tetapi 1–2 kasus batas tidak tertangani | Terdapat 1–2 fitur wajib yang tidak tersedia atau tidak berfungsi dengan benar | Lebih dari 2 fitur wajib tidak tersedia atau tidak berfungsi dengan benar |
| A2. Perancangan struct dan array |   | 5 Menggunakan minimal 2 struct, salah satunya memuat struct lain atau array; array of struct memiliki kapasitas yang dijustifikasi | Penggunaan struct dan array sesuai ketentuan, tetapi rancangannya kurang sistematis | Hanya menggunakan 1 struct atau tidak terdapat struct bersarang | Struct tidak dimanfaatkan secara bermakna |
| A3. Fungsi, header file, dan modularisasi | 5 | Program terbagi menjadi beberapa file (.h/.cpp) berdasarkan modul, setiap fungsi memiliki tanggung jawab tunggal, dan struct/array dilewatkan dengan referensi | Struktur multi-file tersedia, tetapi sebagian fungsi terlalu kompleks atau menggunakan pass by value secara tidak perlu | Header file tersedia, tetapi sebagian besar logika program berada di main.cpp | Program hanya terdiri atas satu file atau tidak menggunakan header file |
| A4. File I/O dan penanganan data tidak valid | 5 | Pembacaan dan penyimpanan berkas berjalan benar; baris dengan format salah, nilai di luar rentang, dan data duplikat ditangani tanpa menyebabkan program berhenti secara tidak normal | Pembacaan dan penyimpanan berkas benar, tetapi 1 jenis data tidak valid tidak tertangani | Hanya salah satu proses (baca atau simpan) yang berfungsi, atau program berhenti secara tidak normal pada data tidak valid | Fitur file I/O tidak berfungsi |
| A5. Efisiensi penggunaan memori | 5 | Tipe data sesuai rentang nilai, urutan anggota struct meminimalkan padding, menu Info Memori menampilkan hasil sizeof, dan tidak terjadi overflow | Sebagian besar tipe data tepat, terdapat 1–2 anggota struct yang tidak efisien | Menu Info Memori tersedia, tetapi pemilihan tipe data tidak didasarkan pada rentang nilai | Menu Info Memori tidak tersedia, atau terjadi overflow akibat tipe data yang terlalu kecil |


## KEMENTERIAN PENDIDIKAN TINGGI, SAINS, DAN TEKNOLOGI

## UNIVERSITAS NEGERI SURABAYA

## FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM PRODI S1 KECERDASAN ARTIFISIAL

Kampus Ketintang, Jalan Ketintang, Gedung E2, Surabaya 60231

Laman: https://ai.unesa.ac.id, Email: ai@unesa.ac.id [URL 🔗](mailto:ai@unesa.ac.id)

| Kriteria | Bobot | 4 – Sangat Baik | 3 – Baik | 2 – Cukup | 1 – Kurang |
| --- | --- | --- | --- | --- | --- |
| A6. Kepatuhan terhadap batasan dan kualitas kode | 5 | Seluruh batasan dipatuhi; penamaan identifier deskriptif, indentasi konsisten, dan komentar proporsional | Seluruh batasan dipatuhi, tetapi konsistensi penulisan kode kurang | Terdapat 1 pelanggaran batasan, atau kode sulit dipahami | Terdapat lebih dari 1 pelanggaran batasan |

## B. Laporan (25 poin)

Laporan dievaluasi berdasarkan kualitas perancangan serta justifikasi atas keputusan implementasi, bukan sekadar deskripsi ulang kode program dalam bentuk kalimat.

| Kriteria | Bobot | 4 – Sangat Baik | 3 – Baik | 2 – Cukup | 1 – Kurang |
| --- | --- | --- | --- | --- | --- |
| B1. Ide dan kesesuaian ruang lingkup | 5 | Ide memuat secara lengkap tema, tujuan, manfaat, rancangan struct, daftar fitur, dan format berkas data; tujuan spesifik dan terukur, manfaat relevan, serta program akhir | Ide lengkap, tetapi tujuan atau manfaat kurang spesifik. | Ide tidak memuat salah satu unsur (tujuan, manfaat, atau rancangan), atau terdapat fitur yang tidak diimplementasikan tanpa penjelasan | Ide tidak lengkap atau program akhir menyimpang jauh dari |
| B2. Flowchart |   | 5 Menggambarkan alur utama dan minimal 2 fungsi utama, menggunakan simbol standar secara tepat, serta konsisten dengan kode program | Lengkap, tetapi terdapat sedikit ketidaksesuaian dengan kode program | Hanya menggambarkan alur utama, atau banyak simbol yang tidak tepat | Tidak bermakna atau tidak sesuai dengan kode program |
| B3. Penjelasan kode per blok | 6 | Setiap blok atau fungsi dijelaskan tujuan dan mekanisme kerjanya, disertai justifikasi pemilihan pendekatan serta alternatif yang dipertimbangkan | Penjelasan jelas, tetapi justifikasi hanya diberikan pada sebagian blok | Penjelasan bersifat deskriptif tanpa justifikasi | Penjelasan minim atau tidak sesuai dengan kode program |
| B4. Makefile | 4 | Prosedur kompilasi dan eksekusi dijelaskan secara sistematis; target, dependensi, dan variabel (CXX, CXXFLAGS) diuraikan; terdapat target clean | Prosedur jelas, tetapi uraian dependensi kurang memadai | Hanya memuat prosedur eksekusi tanpa uraian isi makefile | Makefile tidak dijelaskan |


## KEMENTERIAN PENDIDIKAN TINGGI, SAINS, DAN TEKNOLOGI

## UNIVERSITAS NEGERI SURABAYA

## FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM PRODI S1 KECERDASAN ARTIFISIAL

Kampus Ketintang, Jalan Ketintang, Gedung E2, Surabaya 60231

Laman: https://ai.unesa.ac.id, Email: ai@unesa.ac.id [URL 🔗](mailto:ai@unesa.ac.id)

| Kriteria | Bobot | 4 – Sangat Baik | 3 – Baik | 2 – Cukup | 1 – Kurang |
| --- | --- | --- | --- | --- | --- |
| B5. Analisis penggunaan memori | 3 | Tabel memuat setiap anggota struct (tipe data, rentang nilai, ukuran byte, justifikasi), perbandingan sizeof sebelum dan sesudah optimasi, serta spesifikasi kompiler dan sistem operasi | Tabel lengkap, tetapi tanpa perbandingan sebelum dan sesudah optimasi | Tabel hanya mencakup sebagian anggota struct atau justifikasi tidak jelas | Hanya memuat angka tanpa analisis |
| B6. Catatan kesalahan program |   | 2 Memuat minimal 3 kesalahan aktual beserta gejala atau pesan galat, penyebab, dan cara perbaikannya | Memuat 3 kesalahan, tetapi sebagian kurang terperinci | Hanya memuat 1–2 kesalahan | Uraian terlalu umum atau tidak dapat diverifikasi |

## C. Video Penjelasan (40 poin)

Video dievaluasi berdasarkan kemampuan kelompok menjelaskan, menguji, dan memodifikasi program sesuai instruksi yang diterima setelah pengumpulan kode program.

| Kriteria | Bobot | 4 – Sangat Baik | 3 – Baik | 2 – Cukup | 1 – Kurang |
| --- | --- | --- | --- | --- | --- |
| C1. Penjelasan kode program | 15 | Seluruh anggota menjelaskan bagian kode yang ditetapkan secara runtut, mencakup alur logika, justifikasi implementasi, dan penelusuran (tracing) dengan contoh masukan | Penjelasan benar, tetapi justifikasi atau penelusuran kurang mendalam | Penjelasan sebatas membaca kode tanpa menunjukkan pemahaman alur logika | Penjelasan keliru atau tidak sesuai dengan bagian kode yang ditetapkan |
| C2. Pengujian dengan data uji | 8 | Program dieksekusi menggunakan file data uji tanpa perubahan kode; seluruh data tidak valid tertangani dan keluaran benar | Keluaran benar, tetapi 1 kasus data tidak valid tidak tertangani | Program dapat dieksekusi, tetapi sebagian keluaran tidak benar | Program berhenti secara tidak normal atau pengujian tidak didemonstrasikan |
| C3. Modifikasi program |   | 10 Modifikasi berfungsi dengan benar, perubahan kode ditunjukkan, dan justifikasinya dijelaskan | Modifikasi berfungsi, tetapi penjelasan kurang lengkap | Modifikasi hanya berfungsi sebagian | Modifikasi tidak berfungsi atau tidak dikerjakan |


## KEMENTERIAN PENDIDIKAN TINGGI, SAINS, DAN TEKNOLOGI

## UNIVERSITAS NEGERI SURABAYA

## FAKULTAS MATEMATIKA DAN ILMU PENGETAHUAN ALAM PRODI S1 KECERDASAN ARTIFISIAL

Kampus Ketintang, Jalan Ketintang, Gedung E2, Surabaya 60231

Laman: https://ai.unesa.ac.id, Email: ai@unesa.ac.id [URL 🔗](mailto:ai@unesa.ac.id)

| Kriteria | Bobot | 4 – Sangat Baik | 3 – Baik | 2 – Cukup | 1 – Kurang |
| --- | --- | --- | --- | --- | --- |
| C4. Demonstrasi makefile |   | 4 Mendemonstrasikan make clean dan make, lalu mengubah satu file .cpp dan menjelaskan alasan hanya file tersebut yang dikompilasi ulang | Demonstrasi lengkap, tetapi penjelasan kompilasi ulang kurang tepat | Hanya mendemonstrasikan make dan eksekusi program | Tidak terdapat demonstrasi makefile |
| C5. Kualitas penyajian dan partisipasi | 3 | Seluruh anggota berpartisipasi secara proporsional, penyajian sistematis, serta kualitas audio dan tampilan layar jelas | Partisipasi kurang proporsional atau kualitas teknis video kurang memadai | Terdapat 1 anggota dengan peran sangat minim | Terdapat anggota yang tidak tampil dalam video |

## Ketentuan Pengurangan Nilai

Ketentuan berikut berlaku di luar rubrik dan diterapkan terhadap nilai kelompok.

| Kondisi | Konsekuensi |
| --- | --- |
| Program tidak dapat dikompilasi menggunakan make | Nilai komponen A maksimal 40% dari bobotnya |
| Kode program diubah setelah batas pengumpulan | Nilai kriteria C2 = 0 |
| Keterlambatan pengumpulan | Pengurangan 10% dari nilai akhir untuk setiap hari keterlambatan |
| Anggota kelompok tidak mampu menjelaskan bagian kode yang ditetapkan | Nilai kriteria C1 maksimal pada kategori Kurang |
| Kode program identik atau memiliki kemiripan tinggi dengan kelompok lain | Nilai 0 bagi seluruh kelompok yang terlibat |
