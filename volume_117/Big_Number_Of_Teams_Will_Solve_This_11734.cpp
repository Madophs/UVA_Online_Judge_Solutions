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
    int cases;
    string teamOutput, judgeOutput;
    cin >> cases;
    cin.get();
    for (int c = 1; c <= cases; c++) {
        getline(cin, teamOutput);
        getline(cin, judgeOutput);
        uint32_t i = 0, j = 0;
        bool containsWhiteSpaces = false;
        while (true) {
            if (i >= teamOutput.length()) break;
            if (j >= judgeOutput.length()) break;
            if (teamOutput[i] == judgeOutput[j]) {
                ++i, ++j;
            } else if (teamOutput[i] == ' ') {
                ++i;
                containsWhiteSpaces = true;
            } else {
                break;
            }
        }

        while (i < teamOutput.length()) {
            ++i;
            containsWhiteSpaces = true;
        }

        cout << "Case " << c << ": ";
        if (i == j && i == teamOutput.length() && j == judgeOutput.length()) {
            cout << "Yes\n";
        } else if (containsWhiteSpaces && i == teamOutput.length() && j == judgeOutput.length()) {
            cout << "Output Format Error\n";
        } else {
            cout << "Wrong Answer\n";
        }
    }
    return 0;
}
