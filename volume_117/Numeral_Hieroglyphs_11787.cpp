#include <bits/stdc++.h>
#include <cstdint>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

const unsigned int HIEROGLYPHS_SIZE = 7u;
const char HIEROGLYPHS[HIEROGLYPHS_SIZE] = {'B', 'U', 'S', 'P', 'F', 'T', 'M'};

inline uint32_t getHieroglyphIndex(char c) {
    uint32_t hieroIndex = 0;
    for (; HIEROGLYPHS[hieroIndex] != c; ++hieroIndex);
    return hieroIndex;
}

int hieroglyphToDecimal(string &hieroglyph)
{
    if (getHieroglyphIndex(hieroglyph.front()) < getHieroglyphIndex(hieroglyph.back())) {
        reverse(hieroglyph.begin(), hieroglyph.end());
    }

    int result = 0;
    set<int> uniqOrder;
    uint32_t hieroIndex = 0, lastHieroIndex = 7;
    for (uint32_t i = 0; i < hieroglyph.size();) {
        char hieroChar = hieroglyph[i];
        set<int>::iterator it = uniqOrder.find(hieroChar);
        if (it != uniqOrder.end()) {
            return -1;
        }

        uniqOrder.insert(hieroChar);

        int symbolMatches = 0;
        while (hieroChar == hieroglyph[i]) ++i, ++symbolMatches;
        if (symbolMatches > 9) {
            return -1;
        }

        hieroIndex = getHieroglyphIndex(hieroChar);
        result += symbolMatches * pow(10, hieroIndex);

        if (hieroIndex > lastHieroIndex) {
            return -1;
        }
        lastHieroIndex = hieroIndex;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cases; cin >> cases;
    string input;
    while (cases--) {
        cin >> input;
        int res = hieroglyphToDecimal(input);
        if (res > -1) {
            cout << res << '\n';
        } else {
            cout << "error\n";
        }
    }
    return 0;
}
