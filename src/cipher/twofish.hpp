#ifndef TWOFISH_H
#define TWOFISH_H

#include <fstream>
#include <cstdio>
#include <stdexcept>

#include <cryptopp/cryptlib.h>
#include <cryptopp/secblock.h>
#include <cryptopp/twofish.h>
#include <cryptopp/eax.h>
#include <cryptopp/files.h>
#include <cryptopp/osrng.h>
#include <cryptopp/argon2.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>

#include <string>

bool twofish_cipher(std::string mode, std::string filePath, std::string password);

#endif
