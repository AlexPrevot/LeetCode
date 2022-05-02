class Solution {
public:
    vector<vector<int>> sol;

    void solve(vector<int>& nums, int idx) {
        if (idx >= nums.size()) {
            sol.push_back(nums);
            return;
        }

        unordered_set<int> mem;

        for (int i = idx; i < nums.size(); i++) {
            auto found = mem.find(nums[i]);

            if (found == mem.end()) {
                mem.insert(nums[i]);
                swap(nums[idx], nums[i]);
                solve(nums, idx + 1);
                swap(nums[idx], nums[i]);
            }
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {

        solve(nums, 0);

        return sol;
    }
};