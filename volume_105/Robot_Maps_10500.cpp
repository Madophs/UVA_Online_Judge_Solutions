#include <bits/stdc++.h>
#include <cstdint>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

pair<uint32_t, uint32_t> MOVES[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<string> matrix(12);
vector<string> matrixSol(12);
vector<string> visited(12);
uint32_t n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char c;
    uint32_t x, y;
    while (cin >> n >> m && (n && m)) {
        cin >> x >> y;
        for (uint32_t i = 1; i <= n; ++i) {
            matrix[i].clear();
            matrix[i].push_back('X');
            for (uint32_t j = 1; j <= m; ++j) {
                cin >> c;
                matrix[i].push_back(c);
            }
            matrixSol[i] = "?????????????";
            visited[i] = "?????????????";
        }

        //int ans = traverseMap(x, y);
        int ans = 0;
        stack <pair<uint32_t, uint32_t>>s;
        s.push(make_pair(x, y));
        while (!s.empty()) {
            uint32_t i = s.top().first;
            uint32_t j = s.top().second;
            s.pop();

            matrixSol[i][j] = '0';
            visited[i][j] = '0';

            bool isStacked = false;
            for (uint32_t mov = 0; mov < 4; ++mov) {
                uint32_t xx = i + MOVES[mov].first;
                uint32_t yy = j + MOVES[mov].second;
                if (xx < 1 || yy < 1) continue;
                if (xx > n || yy > m) continue;

                if (matrix[xx][yy] == 'X') {
                    matrixSol[xx][yy] = 'X';
                } else if (matrix[xx][yy] == '0' && matrixSol[xx][yy] == '?') {
                    if (!isStacked) {
                        s.push(make_pair(xx, yy));
                        ++ans;
                    }
                    matrixSol[xx][yy] = '0';
                    isStacked = true;
                } else if (matrix[xx][yy] == '0' && visited[xx][yy] == '?') {
                    if (!isStacked) {
                        s.push(make_pair(xx, yy));
                        ++ans;
                    }
                    matrixSol[xx][yy] = '0';
                    isStacked = true;
                }
            }
        }

        cout << '\n';
        for (uint32_t j = 1; j <= m; ++j) {
            if (j == 1) cout << "|";
            cout << "---|";
        }
        cout << '\n';
        for (uint32_t i = 1; i <= n; ++i) {
            for (uint32_t j = 1; j <= m; ++j) {
                if (j == 1) cout << "|";
                cout << " " << matrixSol[i][j] << " |";
            }
            cout << '\n';
            for (uint32_t j = 1; j <= m; ++j) {
                if (j == 1) cout << "|";
                cout << "---|";
            }
            cout << '\n';
        }
        cout << "\nNUMBER OF MOVEMENTS: " << ans << "\n";
    }
    return 0;
}
