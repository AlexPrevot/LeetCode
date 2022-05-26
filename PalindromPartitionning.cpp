class Solution {
public:
    bool isPalindrom(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }

        return true;
    }

    void solve(vector<vector<string>>& ans, string& s, vector<string>& curr, int idx) {
        if (idx >= s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (isPalindrom(s, idx, i)) {
                curr.push_back(s.substr(idx, i + 1 - idx));
                solve(ans, s, curr, i + 1);
                curr.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string& s) {

        vector<string> ex;
        ex.reserve(s.size()); //this vector will never need a capacity > than s.size()


        vector<vector<string>> ans;
        solve(ans, s, ex, 0);

        return ans;
    }
};