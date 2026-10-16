#ifndef BERKAS_H
#define BERKAS_H

#include "buku.h"

#include <cstddef>
#include <string>

std::size_t bacaBuku(const std::string& namaBerkas, KumpulanBuku& koleksi);
bool simpanBuku(const std::string& namaBerkas, const KumpulanBuku& koleksi);

#endif