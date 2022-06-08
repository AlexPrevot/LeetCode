class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> count(26, 0);

        string ans;

        for (char c : s) count[c - 'a']++;

        for (char ch : order) {
            for (int c = 0; c < count[ch - 'a']; c++) {
                ans.push_back(ch);
            }
            count[ch - 'a'] = 0;
        }

        for (int i = 0; i < count.size(); i++) {
            int c = count[i];
            char a = (char)i + 'a';
            for (int j = 0; j < c; j++) ans.push_back(a);
        }

        return ans;
    }
};