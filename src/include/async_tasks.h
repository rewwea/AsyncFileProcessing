#pragma once
#include <string>
#include <vector>

using namespace std;

extern mutex file_mutex; 

void encryptFile(const string& filename, int shift);
void decryptAndMirror(const string& input_filename, const string& output_filename);
void mergeFilesEvenOdd(const vector<string>& filenames, 
                       const string& even_output, 
                       const string& odd_output);