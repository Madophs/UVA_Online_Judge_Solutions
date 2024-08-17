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

inline bool sameVectors(vector<int> &a, vector<int> &b) {
    for (uint32_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    string word;
    cin >> t;
    cin.get();
    cin.get();
    while (t--) {
        vector<pair<string, vector<int>>> anagrams;
        while (getline(cin, word) && !word.empty()) {
            vector<int> reccur(128, 0);
            for (char &c : word) {
                if (c == ' ') continue;
                ++reccur[(int)(c)];
            }
            anagrams.push_back(make_pair(word, reccur));
        }

        sort(anagrams.begin(), anagrams.end());

        for (uint32_t i = 0; i < anagrams.size(); ++i) {
            string curr_word = anagrams[i].first;
            for (uint32_t j = i+1; j < anagrams.size(); ++j) {
                if (sameVectors(anagrams[i].second, anagrams[j].second)) {
                    cout << curr_word << " = " << anagrams[j].first << '\n';
                }
            }
        }

        if (t) cout << '\n';
    }

    return 0;
}
