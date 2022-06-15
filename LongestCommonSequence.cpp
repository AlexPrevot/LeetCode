class Solution {
public:
    int solve(string& text1, string& text2, vector<vector<int>>& mem, int x, int y) {
        if (x >= mem.size() || y >= mem[0].size()) return 0;
        if (mem[x][y] > -1) return mem[x][y];


        int ans = 0;

        if (text1[x] == text2[y]) ans = solve(text1, text2, mem, x + 1, y + 1) + 1;
        else ans = max(solve(text1, text2, mem, x + 1, y), solve(text1, text2, mem, x, y + 1));

        mem[x][y] = ans;

        return mem[x][y];
    }


    int longestCommonSubsequence(string& text1, string& text2) {
        vector<vector<int>> mem(text1.size(), vector<int>(text2.size(), -1));

        return solve(text1, text2, mem, 0, 0);
    }
};