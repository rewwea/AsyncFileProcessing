#include <thread>
#include <vector>
#include "../src/include/caesar_cipher.h"
#include "../src/include/file_utils.h"
using namespace std;

int main() {
    const int shift = 3;
    const vector<string> files = {"test_files/file1.txt", "test_files/file2.txt", "test_files/file3.txt"};
    const string merged_file = "test_files/file4.txt";

    vector<thread> encrypt_threads;
    for (const auto& file : files) {
        encrypt_threads.emplace_back(encryptFile, file, shift);
    }

    for (auto& t : encrypt_threads) {
        t.join();
    }

    mergeFiles(files, merged_file);
    decryptFile(merged_file, shift);

    return 0;
}