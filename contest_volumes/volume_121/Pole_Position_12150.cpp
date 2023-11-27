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
    cin.tie(nullptr);
    cout.tie(nullptr);
    const uint32_t MAX_CARS = 1e3+2;
    int pole[MAX_CARS];
    int cars, c, p;
    while (cin >> cars && cars) {
        memset(pole, -1, sizeof(int) * cars);
        bool isPossible = true;
        int freePlaces = cars;
        for (int i = 0; i < cars; ++i) {
            cin >> c >> p;
            if (i+p >= 0 && i+p < cars) {
                if (pole[i+p] != -1) isPossible = false;
                else --freePlaces;
                pole[i+p] = c;
            } else {
                isPossible = false;
            }
        }

        if (!isPossible || freePlaces) {
            cout << -1 << '\n';
        } else {
            for (int i = 0; i < cars; ++i) {
                if (i) cout << " ";
                cout << pole[i];
            }
            cout << '\n';
        }
    }
    return 0;
}
