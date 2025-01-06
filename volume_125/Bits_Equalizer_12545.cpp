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
    int marks[128];
    int n, c = 0;
    string str1, str2;
    cin >> n;
    while (n--) {
        cin >> str1 >> str2;
        int ones1 = 0;
        int ones2 = 0;
        int marksSize = 0;
        for (uint32_t i = 0; i < str1.length(); ++i) {
            if (str1[i] == str2[i]) continue;
            if (str1[i] == '?') {
                marks[marksSize++] = i;
            }

            ones1 += str1.at(i) == '1';
            ones2 += str2.at(i) == '1';
        }

        int onesDiff = ones2 - ones1;
        if (onesDiff < 0 || str1.length() != str2.length()) {
            cout << "Case " << ++c << ": -1\n";
            continue;
        }

        int swaps = 0, replaces = 0;
        for (uint32_t i = 0; i < str1.length(); ++i) {
            if (str1[i] == '?') continue;
            if (str1[i] == str2[i]) continue;
            if (str1[i] == '1') {
                ++swaps;
            } else {
                if (ones1 && ones2) {
                    --ones1;
                    --ones2;
                    ++swaps;
                } else {
                    ++replaces;
                }
            }
        }

        for (uint32_t i = 0; i < marksSize; ++i) {
            int j = marks[i];
            if (str2[j] == '1') {
                if (ones1) {
                    ++swaps;
                    --ones1;
                }
            }
            ++replaces;
        }

        int ans = replaces + (swaps / 2);
        cout << "Case " << ++c << ": " << ans << '\n';

    }
    return 0;
}
