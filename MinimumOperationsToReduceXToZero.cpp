class Solution {
public:

    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = -1;
        int total = 0;
        for (int i : nums) total += i;

        int obj = total - x;

        if (obj < 0) return -1;

        int left = 0;
        int right = 0;
        int sum = 0;

        while (right < n) {
            sum += nums[right];


            while (sum > obj) {
                sum -= nums[left];
                left++;
            }

            if (sum == obj)
                ans = max(ans, right - left + 1);


            right++;
        }


        if (ans == -1) return ans;
        return n - ans;
    }
};