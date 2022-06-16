class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> mem;
        //mem.reserve(n);

        for (int i = 0; i < n; i++) {
            auto it = lower_bound(mem.begin(), mem.end(), nums[i]);
            if (it == mem.end()) mem.push_back(nums[i]);
            else *it = nums[i];
        }



        return mem.size();
    }
};