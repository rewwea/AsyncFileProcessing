#include "../src/include/enhanced_caesar.h"

char EnhancedCaesar::transform(char c, int shift) {
    if (isalpha(c)) {
        char base = islower(c) ? 'a' : 'A';
        return (c - base + shift + 26) % 26 + base; 
    }
    return c;
}

string EnhancedCaesar::encrypt(const string& text, int shift) {
    string result = "";
    for (size_t i = 0; i < text.length(); ++i) {
        result += transform(text[i], shift + i); 
    }
    return result;
}

string EnhancedCaesar::decrypt(const string& text, int shift) {
    string result = "";
    for (size_t i = 0; i < text.length(); ++i) {
        result += transform(text[i], -(shift + i));
    }
    return result;
}