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
    vector<int> vec(10001, 0);
    int n, q, c = 0;
    while (cin >> n >> q && n && q) {
        for (int i = 0; i < n; ++i) cin >> vec[i];
        sort(vec.begin(), vec.begin() + n);
        int marble;
        cout << "CASE# " << ++c << ":\n";
        while (q--) {
            cin >> marble;
            auto marbleIter = lower_bound(vec.begin(), vec.begin() + n, marble);
            if (marbleIter != (vec.begin() + n) && *marbleIter == marble) {
                cout << marble << " found at " << ((marbleIter - vec.begin()) + 1) << '\n';
            } else {
                cout << marble << " not found\n";
            }
        }
    }
    return 0;
}
