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
        UnionFind(uint32_t i_size) {
            m_parents.assign(i_size, 0);
            iota(m_parents.begin(), m_parents.end(), 0);
            m_rank.assign(i_size, 0);
            m_setSize.assign(i_size, 1);
            m_numOfSets = i_size;
            m_size = i_size;
        }

        uint32_t findParent(uint32_t i_vertex) {
            if (m_parents[i_vertex] == i_vertex) {
                return i_vertex;
            }
            return m_parents[i_vertex] = findParent(m_parents[i_vertex]);
        }

        bool isSameSet(uint32_t i_vertexA, uint32_t i_vertexB) {
            return findParent(i_vertexA) == findParent(i_vertexB);
        }

        void unionSet(uint32_t i_vertexA, uint32_t i_vertexB) {
            if (isSameSet(i_vertexA, i_vertexB)) {
                return;
            }
            uint32_t vertexAParent = findParent(i_vertexA);
            uint32_t vertexBParent = findParent(i_vertexB);
            if (m_rank[vertexAParent] > m_rank[vertexBParent]) {
                swap(vertexAParent, vertexBParent);
            }
            m_parents[vertexAParent] = vertexBParent;
            if (m_rank[vertexBParent] == m_rank[vertexAParent]) {
                ++m_rank[vertexBParent];
            }
            m_setSize[vertexBParent] += m_setSize[vertexAParent];
            --m_numOfSets;
        }

        uint32_t setSize(int i_vertex) {
            return m_setSize[i_vertex];
        }

        uint32_t size() const {
            return m_size;
        }

    private:
        vector<int> m_parents;
        vector<int> m_rank;
        vector<int> m_setSize;
        uint32_t m_numOfSets;
        uint32_t m_size;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, n, m, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        UnionFind uf(n + 1);
        while (m--) {
            cin >> a >> b;
            uf.unionSet(a, b);
        }
        uint32_t maxSetSize = 0;
        for (int i = 1; i < uf.size(); ++i) {
            maxSetSize = max(uf.setSize(i), maxSetSize);
        }

        cout << maxSetSize << "\n";
    }
    return 0;
}
