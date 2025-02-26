#pragma once
#include <string>
#include <vector>
using namespace std;

class Playfair {
public:
    Playfair(const string& key);
    string encrypt(const string& text);
    string decrypt(const string& text);

private:
    vector<vector<char>> generateSquare(const string& key);
    string prepareText(const string& text);
    pair<int, int> findChar(char c, const vector<vector<char>>& square);
    vector<vector<char>> square;
};