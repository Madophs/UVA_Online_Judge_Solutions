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
    vector<int> vec(10001);
    int n, money;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) cin >> vec[i];
        sort(vec.begin(), vec.begin() + n);
        cin >> money;
        int half = money/2;
        auto middle = lower_bound(vec.begin(), vec.begin() + n, half);
        int i = 0, j = (middle - vec.begin()), sum = 0;
        int book1 = 0, book2 = 0;
        while (sum != money) {
            i = j-1;
            for (; i >= 0; --i) {
                sum = vec[i] + vec[j];
                if (sum < money) break;
                if (sum == money) {
                    book1 = vec[i], book2 = vec[j];
                    break;
                }
            }
            ++j;
        }
        cout << "Peter should buy books whose prices are "<< book1 << " and " << book2 << ".\n\n";
    }
    return 0;
}
