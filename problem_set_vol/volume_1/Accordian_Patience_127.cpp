#include <bits/stdc++.h>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

inline void clearPiles(vector<stack<string>> &piles)
{
    for (auto &s : piles) {
        while (!s.empty())
            s.pop();
    }
}

inline bool isMatch(const string &a, const string &b)
{
    return a.front() == b.front() || a.back() == b.back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    constexpr uint32_t DECK_SIZE = 26 * 2;
    vector<stack<string>> piles(DECK_SIZE);
    string card;
    do {
        cin >> card;
        if (card == "#")
            break;

        uint32_t pileIndex = 0;
        piles[pileIndex++].push(card);
        for (; pileIndex < DECK_SIZE; ++pileIndex) {
            cin >> card;
            piles[pileIndex].push(card);
        }

        uint32_t pilesNo = piles.size();
        string left1stCard, left3rdCard, currCard;
        pileIndex = 1;
        while (pileIndex < pilesNo) {
            currCard = piles[pileIndex].top();
            left1stCard = piles[pileIndex-1].top();
            if (pileIndex > 2) {
                left3rdCard = piles[pileIndex-3].top();
            } else {
                left3rdCard = "XX";
            }

            bool wasCardMoved = false;
            if (isMatch(left1stCard, currCard)) {
                if (isMatch(left3rdCard, currCard)) {
                    piles[pileIndex-3].push(currCard);
                    piles[pileIndex].pop();
                } else {
                    piles[pileIndex-1].push(currCard);
                    piles[pileIndex].pop();
                }
                wasCardMoved = true;
            } else if (isMatch(left3rdCard, currCard)) {
                piles[pileIndex-3].push(currCard);
                piles[pileIndex].pop();
                wasCardMoved = true;
            }

            if (wasCardMoved) {
                if (piles[pileIndex].empty()) {
                    auto swapIndex = pileIndex;
                    while (swapIndex + 1 < pilesNo) {
                        swap(piles[swapIndex], piles[swapIndex + 1]);
                        ++swapIndex;
                    }
                    --pilesNo;
                }
                pileIndex = 1;
            } else {
                ++pileIndex;
            }
        }

        cout << pilesNo << (pilesNo == 1 ? " pile" : " piles") << " remaining:";
        for (auto i = 0u; i < piles.size(); ++i) {
            if (piles[i].empty()) break;
            cout << " " << piles[i].size();
        }
        cout << endl;
        clearPiles(piles);
    } while (true);
    return 0;
}
