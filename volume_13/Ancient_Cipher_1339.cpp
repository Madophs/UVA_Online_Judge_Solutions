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

const int ARR_SIZE = 27;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int arr[ARR_SIZE], arr2[ARR_SIZE];
    string encrypted, original;
    while (cin >> encrypted >> original) {
        memset(arr, 0, sizeof(arr));
        memset(arr2, 0, sizeof(arr2));
        for (char &c : encrypted) ++arr[(int)(c - 'A')];
        for (char &c : original) ++arr2[(int)(c - 'A')];
        sort(arr, arr + ARR_SIZE);
        sort(arr2, arr2 + ARR_SIZE);
        bool equal = true;
        for (int i = 0; i < ARR_SIZE && equal; ++i) {
            if (arr[i] != arr2[i]) equal = false;
        }
        if (equal) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
