class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int curr = 0;

        int minimum = INT_MAX;
        int l = 0; // left
        //r = right
        for (int r = 0; r < n; r++) {
            curr += nums[r];
            while (curr >= target) {
                minimum = min(minimum, r - l + 1);
                curr -= nums[l++];
            }
        }


        return minimum == INT_MAX ? 0 : minimum;
    }
};