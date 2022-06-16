class Solution {
public:
    int longestCommonSubsequence(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        short mem[n + 1][m + 1];
        memset(mem, 0, (m + 1) * (n + 1) * sizeof(short));


        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) mem[i][j] = 1 + mem[i - 1][j - 1];
                else mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]);
            }
        }

        return mem[n][m];

    }
};