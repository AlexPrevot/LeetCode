class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int before = prices[0];

        for (int val : prices) {
            ans += max(0, val - before);
            before = val;
        }
        return ans;
    }
};