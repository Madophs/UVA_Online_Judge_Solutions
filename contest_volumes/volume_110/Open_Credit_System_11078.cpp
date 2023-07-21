#include <bits/stdc++.h>
#include <cstdlib>
#include <limits>

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

const int MIN = numeric_limits<int>::min() + 1;

struct Score {
    int carry;
    int lowest, highest;
    Score() {
        this->lowest = 0;
        this->highest = 0;
        this->carry = MIN;
    }
};

inline int highestCase(int *arr)
{
    int index = 0, maxValue = arr[0];
    for (int i = 1; i < 6; ++i) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
            index = i;
        }
    }
    return index;
}

void inline setValues(Score &obj, Score  obj1, Score obj2, int &score)
{
    obj.highest = max(obj1.highest, obj2.highest);
    obj.lowest = min(obj1.lowest, obj2.lowest);
    obj.carry = score;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int cases[6];
    int t, n;
    cin >> t;
    while (t-- && cin >> n) {
        vector<Score> scores(n, Score());
        for (int i = 0; i < n && cin >> scores[i].highest; ++i) scores[i].lowest = scores[i].highest;
        for (int jump = 1; jump < n; jump <<= 1) {
            for (int i = 0, j = jump; j < n; i += jump, j += jump) {
                cases[0] = scores[i].highest - scores[j].highest;
                cases[1] = scores[i].lowest - scores[j].lowest;
                cases[2] = scores[i].highest - scores[j].lowest;
                cases[3] = scores[i].lowest - scores[j].highest;
                cases[4] = scores[i].carry;
                cases[5] = scores[j].carry;
                int winnerCase = highestCase(cases);
                setValues(scores[i], scores[i], scores[j], cases[winnerCase]);
            }
        }
        cout << scores.front().carry << '\n';
    }
    return 0;
}
