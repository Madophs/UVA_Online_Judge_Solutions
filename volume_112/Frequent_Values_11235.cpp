#include <bits/stdc++.h>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

const int MAX_VALUE = 10e8;

struct Node {
    int val{1};
    int i{-1};
    int j{-1};
};

class SegmentedTree {
public:
    vector<Node> m_values;
    vector<Node> m_tree;

    SegmentedTree(const vector<Node> & i_values)
    {
        m_values.assign(i_values.begin(), i_values.end());
        m_tree.assign(m_values.size() * 4, Node());
        build(1, 0, m_values.size()-1);
    }

    void build(int p, int l, int r)
    {
        if (l == r) {
            m_tree[p] = m_values[l];
        } else {
            int middle = (l + r) / 2;
            int lchild = getLeftChild(p);
            int rchild = getRightChild(p);
            build(lchild, l, middle);
            build(rchild, middle + 1, r);

            if (m_tree[lchild].val >= m_tree[rchild].val) {
                m_tree[p].val = m_tree[lchild].val;
            } else {
                m_tree[p].val = m_tree[rchild].val;
            }
            m_tree[p].i = m_tree[lchild].i;
            m_tree[p].j = m_tree[rchild].j;
        }
    }

    int query(int i, int j)
    {
        return i_query(1, 0, m_values.size()-1, i, j);
    }
private:
    int i_query(int p, int l, int r, int i, int j)
    {
        if (m_tree[p].j < i || m_tree[p].i > j)
            return -1;
        if (i <= m_tree[p].i && m_tree[p].j <= j) {
            return m_tree[p].val;
        } else if (l == r) {
            if (m_tree[p].i <= i && j <= m_tree[p].j) {
                return (j-i) + 1;
            } else if (m_tree[p].i <= i) {
                return (m_tree[p].j - i) + 1;
            } else {
                return (j - m_tree[p].i) + 1;
            }
        } else {
            int lchild = getLeftChild(p);
            int rchild = getRightChild(p);
            int lres = i_query(lchild, l, (l+r)/2, i, j);
            int rres = i_query(rchild, (l+r)/2+1, r, i, j);
            return max(lres, rres);
        }
    }

    int getLeftChild(int p)
    {
        return p << 1;
    }

    int getRightChild(int p)
    {
        return (p << 1) + 1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q, val;
    while (cin >> n && n && cin >> q) {
        vector<Node> values;
        values.reserve(n);
        int lastVal = MAX_VALUE;
        for (int i = 1; i <= n; ++i) {
            Node n;
            cin >> val;
            if (lastVal == val) {
                ++values.back().val;
                ++values.back().j;
            } else {
                values.push_back(n);
                values.back().i = i;
                values.back().j = i;
            }
            lastVal = val;
        }

        SegmentedTree st(values);
        int a, b;
        while (q-- && cin >> a >> b) {
            cout << st.query(a, b) << '\n';
        }
    }
    return 0;
}
