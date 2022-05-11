class Solution {
public:
    int solve(vector<vector<int>>& grid, int x, int y) {
        if (x == grid.size() - 1 && y == grid[0].size() - 1) return !grid[x][y];
        if (x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1) return 0;

        if (grid[x][y] > 0) return grid[x][y];

        grid[x][y] += solve(grid, x + 1, y) + solve(grid, x, y + 1);

        return grid[x][y];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                grid[i][j] *= -1;
            }
        }


        return solve(grid, 0, 0);
    }
};