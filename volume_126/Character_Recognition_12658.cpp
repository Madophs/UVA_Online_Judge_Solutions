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
    int n;
    cin >> n;
    vector<string> lines(5);
    string str;
    for (int i = 0; i < 5; ++i) {
        cin >> lines[i];
    }

    string ans;
    for (int i = 0; i < (n * 4); i+=4) {
        if (lines[0][i] == '*') {
            if (lines[3][i] == '*') {
                ans.push_back('2');
            } else {
                ans.push_back('3');
            }
        } else {
            ans.push_back('1');
        }
    }

    cout << ans << '\n';
    return 0;
}
