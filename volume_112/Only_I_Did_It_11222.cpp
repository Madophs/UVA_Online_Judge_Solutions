#include <bits/stdc++.h>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

void printVector(const vector<int> &vec)
{
    cout << " " << vec.size();
    for (int i = 0; i < vec.size(); ++i) {
        cout << " " << vec[i];
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, n;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        vector<vector<int>> problems(3, vector<int>());
        for (int i = 0; i < 3; ++i) {
            int tmp;
            cin >> n;
            while (n--) {
                cin >> tmp;
                problems[i].push_back(tmp);
            }
            sort(problems[i].begin(), problems[i].end());
        }

        vector<vector<int>> uniqueSolved(3, vector<int>());
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < problems[i].size(); ++j) {
                int searchItem = problems[i][j];
                int isSolvedByOthers = false;
                for (int x = 0; x < 3; ++x) {
                    if (x != i) {
                        if (binary_search(problems[x].begin(), problems[x].end(),  searchItem)) {
                            isSolvedByOthers = true;
                        }
                    }
                }
                if (!isSolvedByOthers) {
                    uniqueSolved[i].push_back(searchItem);
                }
            }
        }

        cout << "Case #" << t << ":\n";
        int maxSolved = max(uniqueSolved[0].size(), max(uniqueSolved[1].size(), uniqueSolved[2].size()));
        for (int i = 0; i < 3; ++i) {
            if (uniqueSolved[i].size() == maxSolved) {
                cout << i+1;
                printVector(uniqueSolved[i]);
            }
        }
    }
    return 0;
}
