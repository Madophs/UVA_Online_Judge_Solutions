#include <bits/stdc++.h>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

const unsigned int FACTORS_NUM = 3;
long long factors[FACTORS_NUM] = {2, 3, 5};

inline bool isUgly(int number)
{
    if (number == 1) return true;
    unsigned int i = 0u;
    long long modRes = number;
    while (modRes != 0LL && i < FACTORS_NUM) {
        if (modRes % factors[i] == 0LL) {
            modRes /= factors[i];
        } else {
            ++i;
        }
    }
    return modRes == 1LL;
}

long long getNthUglyNumber(int pos) {
    long long uglyNumber = 0, p = 0;
    while (p < pos) {
        ++uglyNumber;
        if (isUgly(uglyNumber)) {
            ++p;
        }
    }
    return uglyNumber;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << "The 1500'th ugly number is " << 859963392 << "." << endl;
    return 0;
}
