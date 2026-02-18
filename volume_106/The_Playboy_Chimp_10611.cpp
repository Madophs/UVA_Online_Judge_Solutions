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
    int n, q, h;
    cin >> n;
    vector<int> vec(n);
    for (int &val : vec) cin >> val;
    cin >> q;
    while (q-- && cin >> h) {
        auto c1 = lower_bound(vec.begin(), vec.end(), h);
        auto c2 = upper_bound(vec.begin(), vec.end(), h);
        if (c1 != vec.end()) {
            if ((*c1 >= h && c1 != vec.begin()))
                cout << *(--c1) << " ";
            else if (*c1 < h)
                cout << *c1 << " ";
            else
                cout << "X ";
        } else {
            cout << vec.back() << " ";
        }
        if (c2 != vec.end()) cout << *c2 << "\n";
        else cout << "X\n";
    }
    return 0;
}
