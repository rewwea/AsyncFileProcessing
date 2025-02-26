#include "../src/include/playfair.h"
#include <iostream>
#include <fstream> 
#include <algorithm>

Playfair::Playfair(const string& key) {
    string processedKey = "";
    for (char c : key) {
        if (isalpha(c)) {
            char upper = toupper(c);
            if (upper == 'J') upper = 'I';
            if (processedKey.find(upper) == string::npos)
                processedKey += upper;
        }
    }
    square = generateSquare(processedKey);
}

vector<vector<char>> Playfair::generateSquare(const string& key) {
    vector<vector<char>> square(5, vector<char>(5));
    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // J заменен на I

    int idx = 0;
    for (char c : key) {
        square[idx / 5][idx % 5] = c;
        alphabet.erase(alphabet.find(c), 1);
        idx++;
    }
    for (char c : alphabet) {
        square[idx / 5][idx % 5] = c;
        idx++;
    }
    return square;
}

string Playfair::prepareText(const string& text) {
    string prepared = "";
    for (char c : text) {
        if (isalpha(c)) {
            char upper = toupper(c);
            if (upper == 'J') upper = 'I';
            prepared += upper;
        }
    }
    if (prepared.size() % 2 != 0) prepared += 'X'; // Добавляем разделитель
    return prepared;
}

pair<int, int> Playfair::findChar(char c, const vector<vector<char>>& square) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (square[i][j] == c) return {i, j};
        }
    }
    return {-1, -1};
}

string Playfair::encrypt(const string& text) {
    string prepared = prepareText(text);
    string result = "";
    for (size_t i = 0; i < prepared.length(); i += 2) {
        pair<int, int> p1 = findChar(prepared[i], square);
        pair<int, int> p2 = findChar(prepared[i+1], square);

        // Если буквы в одной строке
        if (p1.first == p2.first) {
            result += square[p1.first][(p1.second + 1) % 5];
            result += square[p2.first][(p2.second + 1) % 5];
        }
        // Если буквы в одном столбце
        else if (p1.second == p2.second) {
            result += square[(p1.first + 1) % 5][p1.second];
            result += square[(p2.first + 1) % 5][p2.second];
        }
        // Иначе углы прямоугольника
        else {
            result += square[p1.first][p2.second];
            result += square[p2.first][p1.second];
        }
    }
    return result;
}

string Playfair::decrypt(const string& text) {
    string prepared = prepareText(text);
    string result = "";
    for (size_t i = 0; i < prepared.length(); i += 2) {
        pair<int, int> p1 = findChar(prepared[i], square);
        pair<int, int> p2 = findChar(prepared[i+1], square);

        // Если буквы в одной строке
        if (p1.first == p2.first) {
            result += square[p1.first][(p1.second - 1 + 5) % 5];
            result += square[p2.first][(p2.second - 1 + 5) % 5];
        }
        // Если буквы в одном столбце
        else if (p1.second == p2.second) {
            result += square[(p1.first - 1 + 5) % 5][p1.second];
            result += square[(p2.first - 1 + 5) % 5][p2.second];
        }
        // Иначе углы прямоугольника
        else {
            result += square[p1.first][p2.second];
            result += square[p2.first][p1.second];
        }
    }
    return result;
}