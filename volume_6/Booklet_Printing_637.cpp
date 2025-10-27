#include <bits/stdc++.h>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int sheetNum;
    while (cin >> sheetNum && sheetNum) {
        int blankNum = 4 - (sheetNum % 4);
        int lowerBoundPage = 1, upperBoundPage = sheetNum;
        int sheetPageNum = 2;
        cout << "Printing order for " << sheetNum << " pages:\n";
        if (blankNum == 2) {
            cout << "Sheet " << (sheetPageNum++ / 2) << ", front: Blank, " << lowerBoundPage++ << "\n";
            if (lowerBoundPage < upperBoundPage || sheetNum == 2)
                cout << "Sheet " << (sheetPageNum++ / 2) << ", back : " << lowerBoundPage++ << ", Blank\n";
        } else if (blankNum == 1) {
            cout << "Sheet " << (sheetPageNum++ / 2) << ", front: Blank, " << lowerBoundPage++ << "\n";
            if (lowerBoundPage < upperBoundPage)
                cout << "Sheet " << (sheetPageNum++ / 2) << ", back : " << lowerBoundPage++ << ", " << upperBoundPage-- << "\n";
        } else if (blankNum == 3) {
            cout << "Sheet " << (sheetPageNum++ / 2) << ", front: Blank, " << lowerBoundPage++ << "\n";
            if (lowerBoundPage < upperBoundPage)
                cout << "Sheet " << (sheetPageNum++ / 2) << ", back : " << lowerBoundPage++ << ", Blank\n";
            if (lowerBoundPage < upperBoundPage)
                cout << "Sheet " << (sheetPageNum++ / 2) << ", front: Blank, " << lowerBoundPage++ << "\n";
            if (lowerBoundPage < upperBoundPage)
                cout << "Sheet " << (sheetPageNum++ / 2) << ", back : " << lowerBoundPage++ << ", " << upperBoundPage-- << '\n';
        }

        while (lowerBoundPage < upperBoundPage) {
            cout << "Sheet " << (sheetPageNum++ / 2) << ", front: " << upperBoundPage << ", " << lowerBoundPage << "\n";
            cout << "Sheet " << (sheetPageNum++ / 2) << ", back : " << ++lowerBoundPage << ", " << --upperBoundPage << "\n";
            ++lowerBoundPage, --upperBoundPage;
        }
    }
    return 0;
}
