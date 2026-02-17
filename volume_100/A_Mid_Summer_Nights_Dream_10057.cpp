#include <bits/stdc++.h>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/
vector<int> vec((int)10e6+1, -1);

int absSum(int len, int v) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += abs(vec[i] - v);
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) cin >> vec[i];
        sort(vec.begin(), vec.begin() + n);
        int median = n / 2 - !(n & 1);
        int A = vec[median];
        int absVal = absSum(n, A);
        auto iter1 = lower_bound(vec.begin(), vec.begin() + median, A);
        auto iter2 = upper_bound(vec.begin() + median + 1, vec.begin() + n, A);

        int satisfy = 1, possibles = 1;
        int leftSatisfy = 0;
        if (iter1 != (vec.begin() + median))
            leftSatisfy = (vec.begin() + median) - iter1;

        int rightSatisfy = (iter2 - (vec.begin() + median + 1));
        if (iter2 != (vec.begin() + n)) {
            int absVal2 = absSum(n, *iter2);
            if (absVal2 == absVal) {
                ++rightSatisfy; // upper median
                possibles += *iter2 - A; // All values between lower - upper median are valid
            }
        }
        satisfy += (leftSatisfy + rightSatisfy);
        cout << A << " " << satisfy << " " << possibles << '\n';
    }
    return 0;
}
