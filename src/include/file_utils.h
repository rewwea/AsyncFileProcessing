#pragma once
#include <string>
#include <vector>
using namespace std;

class FileUtils {
public:
    static string readFile(const string& filename);
    static void writeFile(const string& filename, const string& content);
    static string mirrorText(const string& text);
};