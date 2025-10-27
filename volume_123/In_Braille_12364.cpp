#include <bits/stdc++.h>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/
string brailleSymbols[] = {".***..","*.....", "*.*...", "**....", "**.*..", "*..*..", "***...", "****..", "*.**..", ".**..."};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int D;
    char op;
    while (cin >> D && D) {
        cin >> op;
        if (op == 'S') {
            string digitStream;
            cin >> digitStream;
            for (uint32_t i = 0; i < 6; i+=2) {
                for (uint32_t j = 0; j < digitStream.length(); ++j) {
                    if (j) cout << " ";
                    cout << brailleSymbols[digitStream[j]-'0'][i];
                    cout << brailleSymbols[digitStream[j]-'0'][i + 1];
                }
                cout << "\n";
            }
        } else {
            string brailleInput1, brailleInput2, brailleInput3;
            cin.get();
            getline(cin, brailleInput1);
            getline(cin, brailleInput2);
            getline(cin, brailleInput3);
            for (uint32_t i = 0; i < brailleInput1.length(); i += 3) {
                for (uint32_t j = 0; j < 10u; ++j) {
                    if (brailleInput1[i] == brailleSymbols[j][0] && brailleInput1[i+1] == brailleSymbols[j][1]
                            && brailleInput2[i] == brailleSymbols[j][2] && brailleInput2[i+1] == brailleSymbols[j][3]) {
                        cout << j;
                        break;
                    }
                }
            }
            cout << '\n';
        }
    }
    return 0;
}
