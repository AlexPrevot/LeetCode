class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> mem(n + 1, false);
        mem[n] = true;

        for (int i = n; i > -1; i--) {
            for (string& str : wordDict) {
                if (i + str.size() <= n && s.substr(i, str.size()) == str)
                    mem[i] = mem[i + str.size()];

                if (mem[i]) break;
            }
        }

        return mem[0];
    }
};