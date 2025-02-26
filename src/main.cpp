#include <thread>
#include <vector>
#include <fstream> 
#include "../src/include/playfair.h"
#include "../src/include/file_utils.h"
using namespace std;

void encryptFile(const string& filename, const string& key) {
    Playfair cipher(key);
    ifstream in(filename);
    string content((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    in.close();

    string encrypted = cipher.encrypt(content);
    ofstream out(filename);
    out << encrypted;
    out.close();
}

void decryptFile(const string& filename, const string& key) {
    Playfair cipher(key);
    ifstream in(filename);
    string content((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    in.close();

    string decrypted = cipher.decrypt(content);
    ofstream out(filename);
    out << decrypted;
    out.close();
}

int main() {
    const string key = "PLAYFAIREXAMPLE"; // Ключ для Playfair
    const vector<string> files = {"test_files/file1.txt", "test_files/file2.txt", "test_files/file3.txt"};
    const string merged_file = "test_files/file4.txt";

    vector<thread> encrypt_threads;
    for (const auto& file : files) {
        encrypt_threads.emplace_back(encryptFile, file, key);
    }

    for (auto& t : encrypt_threads) {
        t.join();
    }

    mergeFiles(files, merged_file);
    decryptFile(merged_file, key);

    return 0;
}