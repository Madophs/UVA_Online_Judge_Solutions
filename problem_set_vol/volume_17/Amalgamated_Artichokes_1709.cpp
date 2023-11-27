#include <bits/stdc++.h>
#include <iomanip>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

const double EPSILON = 10e-10;

inline bool faresame(const double& a, const double& b)
{
    return fabs(a - b) < EPSILON;
}

inline bool fishigherthan(const double&a, const double& b)
{
    if (faresame(a, b)) return true;
    return (a-b) > EPSILON;
}

inline double maxDecline(double& p, double& a, double& b, double& c, double& d, const double& K)
{
    vector<double> sequence;
    for (double k = 1; k <= K; ++k) {
        double res = p * (sin(a * k + b) + cos(c * k + d) + 2.0);
        sequence.push_back(res);
    }

    double maxDeclineValue = 0.0;
    double currentMaxValue = 0.0, currentMaxDecline = 0.0;
    for (uint32_t i = 0; i < sequence.size(); ++i) {
        if (__builtin_expect(i, 1)) {
            if (fishigherthan(currentMaxValue, sequence[i])) {
                currentMaxDecline = fmax(currentMaxValue - sequence[i], currentMaxDecline);
            } else {
                currentMaxValue = sequence[i];
                maxDeclineValue = fmax(currentMaxDecline, maxDeclineValue);
                currentMaxDecline = 0.0;
            }
        } else {
            currentMaxValue = sequence[i];
        }
    }
    maxDeclineValue = fmax(currentMaxDecline, maxDeclineValue);
    return maxDeclineValue;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double p, a, b, c, d, k;
    while (cin >> p >> a >> b >> c >> d >> k) {
        double ans = maxDecline(p, a, b, c, d, k);
        cout << fixed << setprecision(6) << ans << '\n';
    }
    return 0;
}
