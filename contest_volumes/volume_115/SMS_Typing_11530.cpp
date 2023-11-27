#include <bits/stdc++.h>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

inline int32_t getKeyTimesPressed(const char &c)
{
    if (c == ' ') return 1;
    if ('a' <= c && c <= 'o') {
        return ((c - 'a') % 3) + 1;
    }
    if (('p' <= c && c <= 's') || ('w' <= c && c <= 'z')) {
        return min(abs('p' - c), abs('w' - c)) + 1;
    }
    return (c - 't') + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int cases;
    string line;
    cin >> cases;
    cin.get();
    for (int i = 1; i <= cases; ++i) {
        getline(cin, line);
        int ans = 0;
        for (char& c : line) {
            ans += getKeyTimesPressed(c);
        }
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}
