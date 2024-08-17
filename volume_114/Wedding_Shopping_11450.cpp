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

int memo[22][102];

inline int max3(int a, int b, int c)
{
    return max(a, max(b, c));
}

int maxAmountOfMoney(int money, int garmentIndex, vector<vector<int>> garments, const int& budget)
{
    if (money > budget || garmentIndex >= garments.size())
        return -1;

    if (memo[garmentIndex][money] != -1)
        return memo[garmentIndex][money];

    int maxValue = -1;
    for (uint32_t j = 0; j < garments[garmentIndex].size(); ++j) {
        int currentCost = money + garments[garmentIndex][j];
        if (currentCost > budget) continue;
        int spentMoney = maxAmountOfMoney(currentCost, garmentIndex + 1, garments, budget);
        maxValue = max3(currentCost, spentMoney, maxValue);
    }
    return memo[garmentIndex][money] = maxValue;
}

int maxAmountOfMoney(vector<vector<int>>& garments, const int& budget)
{
    maxAmountOfMoney(0, 0, garments, budget);
    int lastIndex = garments.size() - 1;
    int maxValue = -1;
    for (int i = 0; i < budget; ++i) {
        maxValue = max(memo[lastIndex][i], maxValue);
    }
    return maxValue;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, m, c, items, value;
    cin >> t;
    while (t-- && cin >> m >> c) {
        vector<vector<int>> garments(c, vector<int>());
        while (c-- && cin >> items) {
            while (items-- && cin >> value) {
                garments[c].push_back(value);
            }
        }
        memset(memo, -1, sizeof(memo));
        int res = maxAmountOfMoney(garments, m);

        if (res != -1) {
            cout << res << '\n';
        } else {
            cout << "no solution\n";
        }

        //for (int i = 0; i < garments.size(); ++i) {
            //for (int j = 0; j < m; ++j) {
                //cout << memo[i][j] << " ";
            //}
            //cout << endl;
        //}
        //cout << endl;
    }

    return 0;
}
