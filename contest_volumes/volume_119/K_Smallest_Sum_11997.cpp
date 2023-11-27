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

template <class T>
class Heap
{
    public:
        Heap();

        template <class Comparator>
        Heap(Comparator cmp);

        template <class InputIterator>
        Heap(InputIterator i_begin, InputIterator i_end);

        template <class InputIterator, class Comparator>
        Heap(InputIterator i_begin, InputIterator i_end, Comparator cmp);

        typename deque<T>::iterator begin() noexcept;

        typename deque<T>::iterator end() noexcept;

        template <class SimpleIterator>
        SimpleIterator end();

        void insert(const T& i_item);

        T pop();

        T top() const;

        T operator[](uint32_t i_index) const { return m_container[i_index]; }

        inline uint32_t size() const;

        inline bool empty() const;

        void clear();
    protected:
        void doBubbleUp(uint32_t i_index);

        void doBubbleDown(uint32_t i_index);

        inline uint32_t doGetParent(const uint32_t& i_index);

        inline uint32_t doGetLeftChild(const uint32_t& i_index);

        inline uint32_t doGetRightChild(const uint32_t& i_index);

        inline static bool doDefaultCmp(const T& a, const T& b);
    private:
        deque<T> m_container;

        bool (*m_cmp) (const T&, const T&);

        const uint32_t ROOT{0};
};

template <class T>
Heap<T>::Heap()
{
    m_cmp = &doDefaultCmp;
}

template <class T>
template <class Comparator>
Heap<T>::Heap(Comparator cmp)
{
    m_cmp = cmp;
}

template <class T>
template <class InputIterator>
Heap<T>::Heap(InputIterator i_begin, InputIterator i_end)
{
    m_cmp = &doDefaultCmp;
    for (;i_begin != i_end; ++i_begin) {
        insert(*i_begin);
    }
}

template <class T>
template <class InputIterator, class Comparator>
Heap<T>::Heap(InputIterator i_begin, InputIterator i_end, Comparator cmp)
{
    m_cmp = cmp;
    for (;i_begin != i_end; ++i_begin) {
        insert(*i_begin);
    }
}

template <class T>
typename deque<T>::iterator Heap<T>::begin() noexcept
{
    return m_container.begin();
}

template <class T>
typename deque<T>::iterator Heap<T>::end() noexcept
{
    return m_container.end();
}

template <class T>
void Heap<T>::insert(const T& i_item)
{
    m_container.push_back(i_item);
    doBubbleUp(m_container.size()-1);
}

template <class T>
T Heap<T>::pop()
{
    swap(m_container.front(), m_container.back());
    T item = m_container.back();
    m_container.pop_back();
    doBubbleDown(ROOT);
    return item;
}

template <class T>
T Heap<T>::top() const
{
    return m_container.front();
}

template <class T>
uint32_t Heap<T>::size() const
{
    return m_container.size();
}

template <class T>
bool Heap<T>::empty() const
{
    return m_container.empty();
}

template <class T>
void Heap<T>::clear()
{
    m_container.clear();
}

// Protected Methods

template <class T>
void Heap<T>::doBubbleUp(uint32_t i_index)
{
    uint32_t parentIndex = doGetParent(i_index);
    while (m_cmp(m_container[i_index], m_container[parentIndex])) {
        swap(m_container[i_index], m_container[parentIndex]);
        i_index = parentIndex;
        parentIndex = doGetParent(i_index);
    }
}

template <class T>
void Heap<T>::doBubbleDown(uint32_t i_index)
{
    uint32_t parent = i_index;
    uint32_t leftChild = doGetLeftChild(parent);
    uint32_t rightChild = doGetRightChild(parent);
    bool onLeft = leftChild < m_container.size() ? m_cmp(m_container[leftChild], m_container[parent]) : false;
    bool onRight = rightChild < m_container.size() ? m_cmp(m_container[rightChild], m_container[parent]) : false;
    do {
        if (onLeft && onRight) {
            if (m_cmp(m_container[leftChild], m_container[rightChild])) {
                doBubbleUp(leftChild);
                parent = leftChild;
            } else {
                doBubbleUp(rightChild);
                parent = rightChild;
            }
        } else {
            if (onLeft) {
                doBubbleUp(leftChild);
                parent = leftChild;
            } else if (onRight) {
                doBubbleUp(rightChild);
                parent = rightChild;
            }
        }
        leftChild = doGetLeftChild(parent);
        rightChild = doGetRightChild(parent);
        onLeft = leftChild < m_container.size() ? m_cmp(m_container[leftChild], m_container[parent]) : false;
        onRight = rightChild < m_container.size() ? m_cmp(m_container[rightChild], m_container[parent]) : false;
    } while (onLeft || onRight);
}

template <class T>
bool Heap<T>::doDefaultCmp(const T&a, const T&b)
{
    return a < b;
}

template <class T>
uint32_t Heap<T>::doGetParent(const uint32_t& i_index)
{
    if (i_index == 0) return 0;
    return (i_index - 1) >> 1;
}

template <class T>
uint32_t Heap<T>::doGetLeftChild(const uint32_t& i_index)
{
    return (i_index << 1) + 1;
}

template <class T>
uint32_t Heap<T>::doGetRightChild(const uint32_t& i_index)
{
    return (i_index << 1) + 2;
}

/******************    START_CODING   ******************/

const int64_t MAX_VALUE = numeric_limits<int64_t>::max();

struct State
{
    int64_t currentSum;
    int32_t index;
    int32_t indexLevel;
    State() {
        currentSum = 0;
        index = 0;
        indexLevel = 0;
    }
    State(int64_t sum, int32_t index, int32_t indexLevel) {
        this->currentSum = sum;
        this->index = index;
        this->indexLevel = indexLevel;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k;
    while (cin >> k) {
        vector<Heap<int64_t>> heaps;
        for (int i = 0; i < k; ++i) {
            Heap<int64_t> h;
            int64_t value;
            for (int j = 0; j < k; ++j) {
                cin >> value;
                h.insert(value);
            }
#ifdef __MDS_DEBUG___
            vector<int64_t> toSort(h.begin(), h.end());
            sort(toSort.begin(), toSort.end());
            for (auto &item : toSort) cout << item << " ";
            cout << endl;
#endif
            heaps.push_back(h);
        }

        vector<vector<int64_t>> queues(k, vector<int64_t>());
        vector<int64_t> results;
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += heaps[i].top();
            queues[i].push_back(heaps[i].pop());
        }
        results.push_back(sum);
        int64_t lastSum = sum;
        for (int32_t i = 0; i < k; ++i) {
            int64_t minSum = 0, tmpSum = 0;
            int32_t lastIndex;
            for (int32_t j = 0; j < k; ++j) {
                tmpSum = (lastSum - queues[j].front()) + heaps[j].top();
                if (j) {
                    if (tmpSum < minSum) {
                        minSum = tmpSum;
                        lastIndex= j;
                    }
                } else {
                    minSum = tmpSum;
                    lastIndex = 0;
                }
            }
            //debug(lastSum, minSum);
            lastSum = minSum;
            int32_t toSum = heaps[lastIndex].top();
            stack<State> s;
            s.push(State());
            s.top().currentSum = toSum;
            //debug(s.top().currentSum);
            while (!s.empty()) {
                State& st = s.top();
                if (st.index < queues[st.indexLevel].size()) {
                    if (st.indexLevel+1 < k) {
                        //debug(st.indexLevel, lastIndex);
                        if (lastIndex == st.indexLevel) {
                            State tmpST(st.currentSum, 0, st.indexLevel + 1);
                            s.push(tmpST);
                        } else {
                            //debug(st.indexLevel, k);
                            State tmpST(st.currentSum + queues[st.indexLevel][st.index], 0, st.indexLevel + 1);
                            s.push(tmpST);
                        }
                    } else {
                        if (lastIndex != st.indexLevel) {
                            for (int64_t &val : queues[st.indexLevel]) {
                                results.push_back(st.currentSum + val);
                                debug(results.back());
                            }
                        } else {
                            results.push_back(st.currentSum);
                            //debug(results.back(), st.indexLevel);
                        }
                        s.pop();
                        if (!s.empty()) {
                            ++s.top().index;
                        }
                    }
                } else {
                    s.pop();
                    if (!s.empty()) {
                        ++s.top().index;
                    }
                }
            }
            //if (heaps[lastIndex].empty()) {
                //cout << "isHappening with " << lastIndex << endl;
            //} else {
                //cout << "hi there " << heaps[lastIndex].top() << " for " << lastIndex << " - " << heaps[lastIndex].size() << endl;
            //}
            if (heaps[lastIndex].empty()) break;
            queues[lastIndex].push_back(heaps[lastIndex].pop());
        }
        sort(results.begin(), results.end());
        for (int i = 0; i < k; ++i) {
            if (i) cout << " ";
            cout << results[i];
        }
        cout << '\n';
    }
    return 0;
}
