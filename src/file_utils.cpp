#include "../src/include/file_utils.h"
#include <fstream>
#include <iostream>
#include <algorithm>

string FileUtils::readFile(const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл " << filename << endl;
        return "";
    }
    return string((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
}

void FileUtils::writeFile(const string& filename, const string& content) {
    ofstream out(filename);
    if (!out.is_open()) {
        cerr << "Ошибка: Не удалось записать в файл " << filename << endl;
        return;
    }
    out << content;
}

string FileUtils::mirrorText(const string& text) {
    return string(text.rbegin(), text.rend()); 
}