#include <bits/stdc++.h>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

constexpr unsigned int MAX_LENGTH = 10000 + 5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int heights[MAX_LENGTH];
    heights[0] = 0;
    char str[MAX_LENGTH];
    str[0] = '_';

    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str+1);
        int ans = 0;
        int heightest = 0, currHeight = 0;
        int len = strlen(str);
        for (int i = 1; i < len; ++i) {
            currHeight += str[i] == '/' && str[i-1] != '\\';
            currHeight -= str[i] == '\\' && str[i-1] == '\\';
            currHeight -= str[i] == '_' && str[i-1] == '\\';
            heights[i] = currHeight;
            if (str[i] == '/' && heightest >= currHeight) {
                int waterCubes = 1;
                for (int j = i-1; j >= 0 && heights[j] != currHeight; --j, ++waterCubes);
                ans += waterCubes;
            }

            heightest = max(currHeight, heightest);
        }
        printf("%d\n", ans);
    }
    return 0;
}
