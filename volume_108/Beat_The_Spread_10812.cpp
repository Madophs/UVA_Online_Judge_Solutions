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
    int c, s, d;
    cin >> c;
    while (c--) {
        cin >> s >> d;
        if (d > s || (s%2 != 0 && d%2 == 0) || (s%2 == 0 && d%2 != 0)) {
            cout << "impossible\n";
        } else {
            int highScore = (s/2) + (d/2+(s&1));
            int lowScore = (s/2) - (d/2);
            cout << highScore << " " << lowScore << endl;
        }
    }
    return 0;
}
