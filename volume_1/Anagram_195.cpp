#include <bits/stdc++.h>
#include <cstdint>

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

bool weirdSort(char a, char b)
{
    if (tolower(a) == tolower(b)) {
        return a < b;
    } else {
        return tolower(a) < tolower(b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    string word;
    cin >> t;

    while (t--) {
        cin >> word;
        sort(word.begin(), word.end(), weirdSort);
        vector<int> vec(word.size(), 0);

        for (uint32_t i = 1; i < word.size(); ++i) {
            if (word.at(i-1) == word.at(i)) {
                vec[i] = vec[i-1];
            } else {
                vec[i] = i;
            }
        }

        do {
            for (int &i : vec) {
                cout << word.at(i);
            }
            cout << '\n';
        } while (next_permutation(vec.begin(), vec.end()));
    }

    return 0;
}
