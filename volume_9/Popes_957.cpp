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
    int y, p;
    while (cin >> y) {
        cin >> p;
        vector<int> vec(p, 0);
        for (uint32_t i = 0u; i < p; ++i) cin >> vec[i];
        int ans = 0, search, l = 0, r = 0;
        for (uint32_t i = 0; i < p; ++i) {
            search = vec[i] + y - 1;
            auto iter = upper_bound(vec.begin(), vec.end(), search);
            int popes = iter - ((vec.begin() + i));
            if (ans < popes) {
                ans = popes;
                l = vec[i];
                if (iter == vec.end()) {
                    r = vec.back();
                } else {
                    if (*iter != search) --iter;
                    r = vec[(iter - vec.begin())];
                }
            }
        }
        cout << ans << " " << l << " " << r << "\n";
    }
    return 0;
}
