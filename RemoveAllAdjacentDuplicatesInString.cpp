class Solution {
public:
    string removeDuplicates(string s, int k) {
        if (s.size() == 1) return s;
        string ans = "";
        vector<pair<char, int>> st;

        for (char c : s) {

            if (st.size() && c == st.back().first) st.back().second++;
            else st.push_back({ c,1 });

            if (st.back().second >= k) st.pop_back();
        }

        for (auto& p : st) {
            for (int i = 0; i < p.second; i++) ans.push_back(p.first);
        }

        return ans;
    }
};