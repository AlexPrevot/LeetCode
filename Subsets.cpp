class Solution {
public:
    vector<vector<int>> sol;

    void solve(vector<int>& nums, vector<int>& curr, int idx) {
        if (idx >= (int)nums.size()) {
            sol.push_back(curr);
            return;
        }

        sol.push_back(curr);

        for (int i = idx + 1; i < nums.size(); i++) {
            vector<int> new_curr = curr;
            new_curr.push_back(nums[i]);
            solve(nums, new_curr, i);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> first;
        solve(nums, first, -1);


        return sol;
    }
};