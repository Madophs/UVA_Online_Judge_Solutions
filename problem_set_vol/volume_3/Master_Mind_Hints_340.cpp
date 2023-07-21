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

    int n, game = 1;
    while (cin >> n && n) {
        vector<int> secretCode(n);
        vector<int> guesses(n);
        bool guessed[n];
        for (int i = 0; i < n && cin >> secretCode[i]; ++i);
        cout << "Game " << game++ << ":\n";
        do {
            for (int i = 0; i < n && cin >> guesses[i]; ++i);
            if (guesses.front() != 0) {
                int strong = 0, weak = 0;
                memset(guessed, false, sizeof(guessed));
                for (int i = 0; i < n; ++i) {
                    if (guesses[i] == secretCode[i]) {
                        ++strong;
                        guessed[i] = true;
                    }
                }

                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (i == j || guessed[j]) continue;
                        if (guesses[i] == secretCode[j] && guesses[i] != secretCode[i]) {
                            ++weak;
                            guessed[j] = true;
                            break;
                        }
                    }
                }
                cout << "    (" << strong << "," << weak << ")\n";
            }
        } while (guesses.front() != 0);
    }

    return 0;
}
