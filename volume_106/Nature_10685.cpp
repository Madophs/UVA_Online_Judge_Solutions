#include <bits/stdc++.h>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

class UnionFind
{
public:
    UnionFind(const size_t i_size)
    {
        m_size = i_size;
        m_vertex.assign(i_size, 0);
        m_rank.assign(i_size, 1);
        m_setSize.assign(i_size, 1);
        m_parent.assign(i_size, 0);
        iota(m_parent.begin(), m_parent.end(), 0);
    }

    size_t size() const
    {
        return m_size;
    }

    unsigned int findParent(unsigned int v)
    {
        if (m_parent[v] == v)
            return v;
        return m_parent[v] = findParent(m_parent[v]);
    }

    bool sameSet(unsigned int v1, unsigned int  v2)
    {
        return findParent(v1) == findParent(v2);
    }

    unsigned int getSetSize(unsigned int v) const
    {
        return m_setSize[v];
    }

    void makeUnion(unsigned int v1, unsigned int v2)
    {
        if (sameSet(v1, v2))
            return;
        unsigned int v1p = findParent(v1);
        unsigned int v2p = findParent(v2);
        if (m_rank[v1p] > m_rank[v2p]){
            swap(v1p, v2p);
        }
        m_parent[v1p] = v2p;
        if (m_rank[v1p] == m_rank[v2p]) {
            ++m_rank[v2p];
        }
        m_setSize[v2p] += m_setSize[v1p];
    }
private:
    size_t m_size;
    vector<unsigned int> m_vertex;
    vector<unsigned int> m_rank;
    vector<unsigned int> m_parent;
    vector<unsigned int> m_setSize;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, c;
    while (cin >> n >> c && (n || c)) {
        UnionFind uf(n);
        unordered_map<string, size_t> creaturesDict;
        string creature1Name, creature2Name;
        while (n--) {
            cin >> creature1Name;
            creaturesDict.insert({creature1Name, creaturesDict.size()});
        }
        while (c--) {
            cin >> creature1Name >> creature2Name;
            unsigned int creature1Index = creaturesDict.find(creature1Name)->second;
            unsigned int creature2Index = creaturesDict.find(creature2Name)->second;
            uf.makeUnion(creature1Index, creature2Index);
        }
        unsigned int largestChain = 0u;
        for (unsigned int i = 0; i < uf.size(); ++i) {
            largestChain = max(uf.getSetSize(i), largestChain);
        }
        cout << largestChain << '\n';
    }
    return 0;
}
