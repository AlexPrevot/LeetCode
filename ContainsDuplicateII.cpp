class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        k = min(n, k);
        unordered_set<int> mem;

        for (int i = 0; i < n; i++) {
            if (i > k) mem.erase(nums[i - k - 1]);
            if (mem.find(nums[i]) != mem.end()) return true;
            else mem.insert(nums[i]);
        }


        return false;
    }
};