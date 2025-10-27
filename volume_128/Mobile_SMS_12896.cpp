#include <bits/stdc++.h>
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
    cin.tie(0);
    cout.tie(0);
    vector<string> keyboard={" ", ".,?\"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<int> keys, freq;
    int t, l, n, p;
    cin >> t;
    while (t--) {
        cin >> l;
        for (int i = 0; i < l && cin >> n; ++i) keys.push_back(n);
        for (int i = 0; i < l && cin >> p; ++i) freq.push_back(p);

        for (int i = 0; i < l; ++i) {
            int index = (freq[i]-1) % keyboard[keys[i]].length();
            cout << keyboard[keys[i]][index];
        }
        cout << '\n';

        keys.clear(), freq.clear();
    }
    return 0;
}
