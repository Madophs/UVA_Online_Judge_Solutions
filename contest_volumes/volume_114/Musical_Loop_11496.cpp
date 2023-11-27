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
    int n;
    while (cin >> n && n) {
        vector<int> samples(n);
        for (auto& val : samples) cin >> val;
        samples.push_back(samples.front());
        samples.push_back(samples[1]);
        int peaks = 0;
        for (uint32_t i = 1; i < samples.size()-1; ++i) {
            peaks += (samples[i] > samples[i-1] && samples[i] > samples[i+1]);
            peaks += (samples[i] < samples[i-1] && samples[i] < samples[i+1]);
        }
        cout << peaks << '\n';
    }
    return 0;
}
