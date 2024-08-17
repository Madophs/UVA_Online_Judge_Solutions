#include <bits/stdc++.h>

using namespace std;

#ifdef __MDS_DEBUG__
template <typename Arg, typename... Args>
void mds_debug(std::ostream& out, Arg&& arg, Args&&... args)
{
    stringstream ss(forward<Arg>(arg));
    vector<string> varnames;
    for (string var; getline(ss, var, ','); varnames.push_back(var)) {
        if (var.at(0) == ' ') var.erase(0, 1);
    }
    using expander = int[];
    uint32_t index = 0;
    (void)expander{0, (void(out << (index ? ", " : "Debug: ") << varnames[index++] << " = " << std::forward<Args>(args)), 0)...};
    out << std::endl;
}
#define debug(...) mds_debug(cerr, #__VA_ARGS__, __VA_ARGS__);
#else
#define debug(...)
#endif

/******************    START_CODING   ******************/

const int LIMIT = 5 * 60 * 60;

bool cycleIsContained(int a, int b, int c, int d) {
    if (c >= a && (d <= b || d >= b) && d > a) return true;
    if (c < a && (d <= b || d >= b) && d > a) return true;
    return false;
}

string formatResult(int value) {
    if (value > LIMIT)
        return "Signals fail to synchronise in 5 hours\n";
    int secs = value % 60; value /= 60;
    int mins = value % 60; value /= 60;
    int hrs = value % 60;
    stringstream ss;
    ss << fixed << setfill('0') << setw(2) << hrs << ':';
    ss << setw(2) << mins << ':' << setw(2) << secs << '\n';
    return ss.str();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int cycle;
    while (cin >> cycle && cycle) {
        vector<int> cycles;
        cycles.push_back(cycle);
        for (;cin >> cycle && cycle; cycles.push_back(cycle));
        sort(cycles.begin(), cycles.end());
        vector<int> cycleTmp(cycles.size(), 0);
        while (true) {
            cycleTmp.front() += cycles.front() << 1;
            int startingCycle = cycleTmp.front();
            int endingCycle = startingCycle + cycles.front() - 5;
            for (int i = 1; i < cycles.size(); ++i) {
                while (!cycleIsContained(startingCycle, endingCycle, cycleTmp[i], (cycleTmp[i] + cycles[i] - 5))) {
                    cycleTmp[i] += cycles[i] << 1;
                }
            }

            int lowerbound = startingCycle, upperbound = startingCycle + cycles.front() - 5;
            for (uint32_t i = 1; i < cycles.size(); ++i) {
                lowerbound = max(cycleTmp[i], lowerbound);
                upperbound = min(cycleTmp[i] + cycles[i] - 5, upperbound);
            }

            if (lowerbound < upperbound || lowerbound > LIMIT) {
                cout << formatResult(lowerbound);
                break;
            }
        }
    }
    cin >> cycle >> cycle;
    return 0;
}
