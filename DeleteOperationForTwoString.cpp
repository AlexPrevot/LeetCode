class Solution {
public:
    int minDistance(string& w1, string& w2) {


        int n = w1.size();
        int m = w2.size();

        vector<vector<int>> mem(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (w1[i - 1] == w2[j - 1]) mem[i][j] = 1 + mem[i - 1][j - 1];
                else mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]);
            }
        }

        return (n - mem[n][m]) + (m - mem[n][m]);
    }
};