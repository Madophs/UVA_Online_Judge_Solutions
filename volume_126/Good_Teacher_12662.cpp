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
    vector<string> students;
    string student;
    int n, q, pos;
    cin >> n;
    while (n-- && cin >> student) students.push_back(student);
    cin >> q;
    while (q-- && cin >> pos) {
        --pos;
        if (students[pos] != "?") {
            cout << students[pos] << '\n';
        } else {
            int l = pos, r = pos;
            while (l > -1 && students[l] == "?") --l;
            while (r < students.size() && students[r] == "?") ++r;
            if (l == -1) {
                int steps = r - pos;
                while (steps--) {
                    cout << "left of ";
                }
                cout << students[r] << '\n';
            } else if (r == students.size()) {
                int steps = pos - l;
                while (steps--) {
                    cout << "right of ";
                }
                cout << students[l] << '\n';
            } else {
                int stepsLeft = r - pos;
                int stepsRight = pos - l;
                if (stepsLeft == stepsRight) {
                    cout << "middle of " << students[l] << " and " << students[r] << '\n';
                } else if (stepsLeft < stepsRight) {
                    while (stepsLeft--) {
                        cout << "left of ";
                    }
                    cout << students[r] << '\n';
                } else {
                    while (stepsRight--) {
                        cout << "right of ";
                    }
                    cout << students[l] << '\n';
                }
            }
        }
    }
    return 0;
}
