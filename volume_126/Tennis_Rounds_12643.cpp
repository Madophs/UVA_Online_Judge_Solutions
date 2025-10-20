#include <bits/stdc++.h>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

inline bool isInLowerPartition(int i, int padding, int partitionSize) {
    return i <= (padding + partitionSize) &&
           i > padding;
}

inline bool isInUpperPartition(int i, int padding, int partitionSize) {
    return i > (padding + partitionSize) &&
           i <= (padding + partitionSize * 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, i, j;
    while (cin >> n >> i >> j) {
        if (i > j) swap(i, j);
        int teams = pow(2, n);
        int level = n+1;
        int padding = 0;
        int partitionSize = teams;
        bool flag1 = false, flag2 = false;
        do {
            --level;
            partitionSize /= 2;
            flag1 = isInLowerPartition(i, padding, partitionSize);
            flag2 = isInUpperPartition(j, padding, partitionSize);

            if (flag2) {
                padding += partitionSize;
            }

        } while ((!flag1 || !flag2) && partitionSize > 1);
        cout << level << endl;
    }
    return 0;
}
