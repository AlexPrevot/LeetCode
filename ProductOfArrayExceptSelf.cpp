class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prod1[n + 1];
        int prod2[n + 1];
        prod1[0] = 1;
        prod2[n] = 1;

        for (int i = 1; i < n + 1; i++) prod1[i] = nums[i - 1] * prod1[i - 1];
        for (int i = n - 1; i > -1; i--) prod2[i] = nums[i] * prod2[i + 1];

        vector<int> ans(n);

        for (int i = 0; i < n; i++) ans[i] = prod1[i] * prod2[i + 1];



        return ans;
    }
};