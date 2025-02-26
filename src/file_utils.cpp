#include "../src/include/file_utils.h"
#include <fstream>
#include <iostream>
using namespace std;

void mergeFiles(const vector<string>& input_files, const string& output_file) {
    ofstream out(output_file);
    if (!out.is_open()) {
        cerr << "Ошибка: Не удалось создать файл " << output_file << endl;
        return;
    }

    for (const auto& file : input_files) {
        ifstream in(file);
        if (!in.is_open()) {
            cerr << "Ошибка: Не удалось открыть файл " << file << endl;
            continue;
        }

        out << in.rdbuf();
        in.close();
    }
    out.close();
}