class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> mem = triangle[n - 1];

        for (int i = n - 2; i > -1; i--) {
            for (int j = 0; j <= i; j++)
                mem[j] = triangle[i][j] + min(mem[j], mem[j + 1]);
        }


        return mem[0];
    }
};