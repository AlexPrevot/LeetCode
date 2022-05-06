class Solution {
public:
    unordered_map<char, char> close;

    bool isValid(string s) {
        stack<char> st;
        close = { {'(',')'},{'{','}'},{'[',']'} };
        for (char c : s) {
            unordered_map<char, char>::iterator it;
            if (st.size()) it = close.find(st.top());
            if (st.size() && it != close.end() && it->second == c)
                st.pop();
            else st.push(c);
        }
        return !st.size();
    }
};