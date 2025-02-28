#include <thread>
#include <vector>
#include <future>
#include <iostream>
#include "../src/include/async_tasks.h"

using namespace std;

int main() {
    const vector<string> files = {"test_files/file1.txt", "test_files/file2.txt", 
                                  "test_files/file3.txt", "test_files/file4.txt"};
    const string merged_even = "test_files/merged_file1.txt";
    const string merged_odd = "test_files/merged_file2.txt";
    const string final_output = "test_files/decrypted_mirror_file.txt";

    vector<future<void>> encryption_tasks;
    for (size_t i = 0; i < files.size(); ++i) {
        encryption_tasks.emplace_back(async(launch::async, encryptFile, files[i], i + 1));
    }
    for (auto& task : encryption_tasks) task.get();

    mergeFilesEvenOdd(files, merged_even, merged_odd);

    async(launch::async, decryptAndMirror, merged_even, final_output);
    async(launch::async, decryptAndMirror, merged_odd, final_output);

    cout << "Обработка завершена!" << endl;
    return 0;
}