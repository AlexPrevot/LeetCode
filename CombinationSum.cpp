class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& can, vector<int>& curr, int sum, int target, int idx) {
        if (sum > target) return;
        if (sum == target) ans.push_back(curr);



        for (int i = idx; i < can.size(); i++) {
            sum += can[i];
            curr.push_back(can[i]);
            solve(can, curr, sum, target, i);
            curr.pop_back();
            sum -= can[i];
        }

    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;

        solve(candidates, curr, 0, target, 0);

        return ans;
    }
};