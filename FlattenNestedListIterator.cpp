class NestedIterator {
public:
    vector<int> copy;
    int ptr;
    NestedIterator(vector<NestedInteger>& nestedList) {
        unwrap(nestedList);
        ptr = 0;
    }

    int next() {
        int ans = copy[ptr];
        ptr++;
        return ans;
    }

    bool hasNext() {
        return ptr < copy.size();
    }

private:
    void unwrap(vector<NestedInteger>& ni) {
        for (NestedInteger& e : ni) {
            if (e.isInteger()) copy.push_back(e.getInteger());
            else unwrap(e.getList());
        }
    }
};