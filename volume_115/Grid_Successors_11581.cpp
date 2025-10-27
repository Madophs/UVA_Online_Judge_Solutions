#include <bits/stdc++.h>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

const int ADJ[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
string grid[3] = {"", "", ""};

int adjSum(int x, int y) {
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        int xx = x + ADJ[i][0];
        int yy = y + ADJ[i][1];
        if (xx < 0 || yy < 0) continue;
        if (xx > 2 || yy > 2) continue;
        sum += (grid[xx][yy] - '0');
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        for (int x = 0; x < 3; cin >> grid[x++]);

        if (grid[0] == "000" && grid[1] == "000" && grid[2] == "000") {
            cout << "-1\n";
            continue;
        }

        int maxIndex = -1;
        do {
            ++maxIndex;
            string gridTmp[3] = {"000", "000", "000"};
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int sum = adjSum(i, j) % 2;
                    gridTmp[i][j] = (sum + '0');
                }
            }
            for (int x = 0; x < 3; ++x) grid[x] = gridTmp[x];
        } while (grid[0] != "000" || grid[1] != "000" || grid[2] != "000");

        cout << maxIndex << '\n';
    }
    return 0;
}
