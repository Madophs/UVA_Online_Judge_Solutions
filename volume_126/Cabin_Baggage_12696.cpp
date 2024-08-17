/**
 * Author: madophs
 * Date: 15/08/2024
 * Problem: Cabin Baggage - 12696
 */

#include <bits/stdc++.h>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

const float MAX_LENGTH = 56.0f;
const float MAX_WIDTH = 45.0f;
const float MAX_DEPTH = 25.0f;
const float MAX_WEIGHT = 7.0f;
const float MAX_TOTAL_LENGTH = 125.0f;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, allowed = 0;
    cin >> n;
    float length, width, depth, weight;
    while (cin >> length >> width >> depth >> weight && n--) {
        if (weight > MAX_WEIGHT) {
            cout << 0 << '\n';
            continue;
        }
        bool isSizeAllowed = length <= MAX_LENGTH && width <= MAX_WIDTH && depth <= MAX_DEPTH;
        float totalLength = length + width + depth;
        if (isSizeAllowed || totalLength <= MAX_TOTAL_LENGTH) {
            cout << "1\n";
            ++allowed;
        } else {
            cout << "0\n";
        }
    }
    cout << allowed << '\n';
    return 0;
}
