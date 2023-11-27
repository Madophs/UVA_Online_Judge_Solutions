#include <bits/stdc++.h>
#include <unordered_map>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    unordered_map<char, char> cipher;
    string line, alpha1, alpha2;
    int cases;
    cin >> cases;
    cin.get(); cin.get();
    while (cases--) {
        getline(cin, alpha1);
        getline(cin, alpha2);

        cipher.clear();
        for (uint32_t i = 0; i < alpha1.length(); ++i) {
            cipher[alpha1.at(i)] = alpha2.at(i);
        }
        vector<string> rawLines;
        while (getline(cin, line) && !line.empty()) {
            rawLines.push_back(line);
        }
        vector<string> resultSet;
        for (const string& entry : rawLines) {
            string resultLine;
            for (const char& c : entry) {
                if (cipher.find(c) != cipher.end()) {
                    resultLine.push_back(cipher[c]);
                } else {
                    resultLine.push_back(c);
                }
            }
            resultSet.push_back(resultLine);
        }

        cout << alpha2 << '\n';
        cout << alpha1 << '\n';
        for (const string& entry : resultSet) {
            cout << entry << '\n';
        }
        if (cases) cout << '\n';
    }
    return 0;
}
