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
    string card, spelling;
    int n;
    while (cin >> n && n) {
        vector<string> arrangement(n);
        int index = -1;
        while (n--) {
            cin >> card >> spelling;
            int steps = spelling.length();
            while (steps--) {
                do {
                    ++index;
                    if (index >= arrangement.size())
                        index %= arrangement.size();
                } while (!arrangement[index].empty());
            }
            arrangement[index] = card;
        }

        for (int i = 0; i < arrangement.size(); ++i) {
            if (i) cout << " ";
            cout << arrangement[i];
        }
        cout << '\n';
    }
    return 0;
}
