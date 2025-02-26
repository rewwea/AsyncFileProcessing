#include "../src/include/caesar_cipher.h"
#include <fstream>
#include <cctype>
#include <iostream>
using namespace std;

void encryptFile(const string& filename, int shift) {
    ifstream in(filename);
    if (!in.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл " << filename << " для шифрования" << endl;
        return;
    }

    string content((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    in.close();

    if (content.empty()) {
        cerr << "Предупреждение: Файл " << filename << " пуст" << endl;
        return;
    }

    for (char& c : content) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
    }

    ofstream out(filename);
    if (!out.is_open()) {
        cerr << "Ошибка: Не удалось перезаписать файл " << filename << endl;
        return;
    }
    out << content;
    out.close();
}

void decryptFile(const string& filename, int shift) {
    encryptFile(filename, -shift);
}