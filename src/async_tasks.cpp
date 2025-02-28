#include "../src/include/async_tasks.h"
#include <mutex>
#include "../src/include/enhanced_caesar.h"
#include "../src/include/file_utils.h"

using namespace std;
mutex file_mutex;

void encryptFile(const string& filename, int shift) {
    lock_guard<mutex> lock(file_mutex);
    string content = FileUtils::readFile(filename);
    string encrypted = EnhancedCaesar::encrypt(content, shift);
    FileUtils::writeFile(filename, encrypted);
}

void decryptAndMirror(const string& input_filename, const string& output_filename) {
    string content = FileUtils::readFile(input_filename);
    string decrypted = EnhancedCaesar::decrypt(content, 3); // Пример сдвига
    string mirrored = FileUtils::mirrorText(decrypted);
    FileUtils::writeFile(output_filename, mirrored);
}

void mergeFilesEvenOdd(const  vector< string>& filenames, 
                       const  string& even_output, 
                       const  string& odd_output) {
     string even_content = "", odd_content = "";
    for (size_t i = 0; i < filenames.size(); ++i) {
         string content = FileUtils::readFile(filenames[i]);
        if ((i + 1) % 2 == 0) {
            even_content += content;
        } else {
            odd_content += content;
        }
    }
    FileUtils::writeFile(even_output, even_content);
    FileUtils::writeFile(odd_output, odd_content);
}