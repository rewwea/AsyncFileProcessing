#pragma once

#include <string>

void encryptFile(const std::string& filename, int shift);
void decryptFile(const std::string& filename, int shift);