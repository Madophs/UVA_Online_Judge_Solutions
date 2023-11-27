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

const string PIZZA = "MARGARITA";
const int MAX = numeric_limits<int>::max();
vector<int> recipe(27, 0);

inline void buildPizzaFreq(vector<int>& vec, const string& ingredients)
{
    for (const char &c : ingredients) {
        ++vec[c-'A'];
    }
}

uint32_t howManyPizzas(vector<int>& ingredients)
{
    vector<int> tmpCounter(27, 0);
    static vector<char> recipeLetter({'M', 'A', 'R', 'G', 'I', 'T'});
    uint32_t ans = MAX;
    for (uint32_t i = 0; i < 6u; ++i){
        int freq = ingredients[recipeLetter[i]-'A'];
        int req = recipe[recipeLetter[i]-'A'];
        uint32_t cant = freq / req;
        ans = min(cant, ans);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    buildPizzaFreq(recipe, PIZZA);
    int t;
    string line;
    cin >> t;
    while (t-- && cin >> line) {
        vector<int> ingredients(27);
        buildPizzaFreq(ingredients, line);
        cout << howManyPizzas(ingredients) << '\n';
    }
    return 0;
}
