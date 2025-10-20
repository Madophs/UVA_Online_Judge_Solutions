#include <bits/stdc++.h>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

inline void markRoad(string &str, uint32_t index) {
    if (index < 0 || index >= str.length()) return;
    if (str[index] != '-') return;
    str[index] = 'X';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, t;
    string road;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> road;
        for (int i = 0; i < road.length(); ++i) {
            if (road[i] == 'B') {
                markRoad(road, i - 1);
                markRoad(road, i - 2);
            } else if (road[i] == 'S') {
                markRoad(road, i - 1);
                markRoad(road, i + 1);
            }
        }

        int ans = 0;
        for (const char & item : road) {
            if (item == '-') ++ans;
        }

        cout << "Case " << t << ": " << ans << '\n';
    }
    return 0;
}
