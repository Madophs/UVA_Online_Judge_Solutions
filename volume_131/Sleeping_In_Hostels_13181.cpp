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
    string line;
    while (cin >> line) {
        vector<int> bedsLocations;
        for (uint32_t i = 0; i < line.length(); ++i) {
            if (line[i] == 'X') {
                bedsLocations.push_back(i);
            }
        }
        int ans = bedsLocations.front() == 0 ? 0 : bedsLocations.front()-1;
        for (uint32_t i = 0; i < bedsLocations.size() - 1u; ++i) {
            if (bedsLocations[i + 1] - bedsLocations[i] == 1) continue;
            int gap = bedsLocations[i + 1] - bedsLocations[i] - 1;
            ans = max((gap - 1) / 2, ans);
        }
        if (line.back() == '.') {
            ans = max((int)((line.length()-2) - bedsLocations.back()), ans);
        }
        cout << ans << '\n';
    }
    return 0;
}
