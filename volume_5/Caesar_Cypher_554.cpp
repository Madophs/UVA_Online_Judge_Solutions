#include <bits/stdc++.h>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

inline int letterDiff(char a, char b)
{
    if (b == ' ') b = 'A' - 1;
    if (a <= b) {
        return b - a;
    } else {
        return ('Z' - a) + (b - ('A' - 2));
    }
}

int wordDifference(const string &word, const string &text)
{
    for (uint32_t y = 0; y < (text.length() - word.length()) + 1; ++y) {
        int diff = letterDiff(word[0], text[y]);
        uint32_t i = 1, j = y+1;
        for (; i < word.length(); ++i, ++j) {
            if (letterDiff(word[i], text[j]) != diff) {
                break;
            }
        }

        if (i == word.length()) {
            return diff;
        }
    }
    return -1;
}

void decrypt(string &text, int key)
{
    if (!key) return;

    for (char &c : text) {
        if (c == ' ') c = 'A' - 1;
        if (('A' - 1) <= ((int) (c - key))) {
            c = (char)(c - key);
        } else {
            int letterPos = key - (c - ('A' - 1));
            letterPos = ('Z' + 1) - letterPos;
            c = (char) letterPos;
        }
        if (c == ('A' - 1)) c = ' ';
    }
}

inline void print(const string &text) {
    string word;
    word.reserve(24);
    int lineLength = 0;
    for (uint32_t i = 0; i < text.length(); ++i) {
        for (;i < text.length() && text[i] != ' '; ++i) {
            word.push_back(text[i]);
        }

        int wordLength = word.length();
        if (lineLength > 0) ++wordLength;
        if (lineLength + wordLength > 60) {
            cout << '\n';
            lineLength = 0;
        }
        if (lineLength > 0) cout << " ";
        cout << word;
        lineLength += wordLength;
        word.clear();
    }
    cout << '\n';
}

int encryptKey(const string &text, const vector<string> &words) {
    int keys[28];
    memset(keys, 0, sizeof(keys));
    for (auto word : words)
    {
        int keyTmp = wordDifference(word, text);
        if (keyTmp != -1) {
            ++keys[keyTmp];
        }
    }

    int key = 0, freq = keys[0];
    for (int i = 1; i < 28; ++i) {
        if (freq < keys[i]) {
            key = i;
            freq = keys[i];
        }
    }
    return key;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<string> words;
    string input, text;
    while (cin >> input && input != "#") {
        words.push_back(input);
    }
    cin.get();
    getline(cin, text);
    decrypt(text, encryptKey(text, words));
    print(text);
    return 0;
}
