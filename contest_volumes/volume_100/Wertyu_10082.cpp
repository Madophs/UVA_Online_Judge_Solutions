#include <bits/stdc++.h>
#include <cctype>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

vector<vector<char>> keyword(
    {
        {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='},
        {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'},
        {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\''},
        {'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/'}
    }
);

inline char getPrevKey(const char& c) {
    if (c == ' ') {
        return c;
    }

    for (uint32_t i = 0; i < keyword.size(); ++i) {
        for (uint32_t j = 0; j < keyword[i].size(); ++j) {
            if (c == keyword[i][j]) {
                if (!j) {
                    continue;
                }
                return keyword[i][j-1];
            }
        }
    }

    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string line, result;
    while (getline(cin, line)) {
        result.clear();
        for (char& c : line) {
            result.push_back(getPrevKey(c));
        }
        cout << result << endl;
    }
    return 0;
}
