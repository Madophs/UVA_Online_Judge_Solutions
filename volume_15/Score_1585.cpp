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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    string line;
    cin >> t;
    while (t-- && cin >> line) {
        int score = 0, accum = 1;
        for (int i = 0; i < (int)line.length(); ++i) {
            if (line[i] == 'O') {
                if (i && line[i-1] == 'O') ++accum;
                score += accum;
            } else {
                accum = 1;
            }
        }
        cout << score << '\n';
    }

    return 0;
}
