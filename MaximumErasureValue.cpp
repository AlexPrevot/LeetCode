class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> mem(10001, -1);
        int l = 0;
        int sum = 0;
        int ans = INT_MIN;

        // l = left, r = right
        for (int r = 0; r < n; r++) {
            int curr = nums[r];
            while (l < r && mem[curr] != -1) {
                sum -= nums[l];
                mem[nums[l]] = -1;
                l++;
            }
            sum += curr;
            mem[curr] = 1;
            ans = max(ans, sum);
        }
        return ans;
    }
};