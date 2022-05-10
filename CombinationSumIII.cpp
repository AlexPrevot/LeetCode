class Solution {
public:

    vector<vector<int>> answer;


    void solve(vector<int>& curr, int idx, int sum, int k, int n) {
        if (sum == n && curr.size() >= k) {
            answer.push_back(curr);
            return;
        }
        if (curr.size() >= k) return;
        if (sum >= n) return;

        for (int i = idx + 1; i <= 9; i++) {
            auto new_curr = curr;
            new_curr.push_back(i);

            solve(new_curr, i, sum + i, k, n);
        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;

        solve(curr, 0, 0, k, n);

        return answer;
    }
};