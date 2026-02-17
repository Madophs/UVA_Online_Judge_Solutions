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
    int c, d, i;
    cin >> c;
    while (c--) {
        cin >> d >> i;
        int ans = 1;
        for (int iter = d-1; iter > 0; --iter) {
            if (i&1) {
                ans<<=1;
            } else {
                ans = (ans << 1) + 1;
            }
            i=(i+1)/2;
        }
        cout << ans << '\n';
    }
    cin >> c;
    return 0;
}
