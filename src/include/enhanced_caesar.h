#pragma once
#include <string>
#include <vector>
using namespace std;

class EnhancedCaesar {
public:
    static string encrypt(const string& text, int shift);
    static string decrypt(const string& text, int shift);

private:
    static char transform(char c, int shift);
};