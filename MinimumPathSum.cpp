class Solution {
public:
    int minPathSum(vector<vector<int>>& grid, vector<vector<int>>& mem, int x, int y) {
        if (x >= grid.size() || y >= grid[0].size()) return INT_MAX;
        if (mem[x][y] > -1) return mem[x][y];

        int below = minPathSum(grid, mem, x + 1, y);
        int right = minPathSum(grid, mem, x, y + 1);

        int ans = min(below, right);

        mem[x][y] = grid[x][y] + ans;

        return mem[x][y];
    }


    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> mem(grid.size(), vector<int>(grid[0].size(), -1));
        mem[grid.size() - 1][grid[0].size() - 1] = grid.back().back();

        return minPathSum(grid, mem, 0, 0);
    }
};