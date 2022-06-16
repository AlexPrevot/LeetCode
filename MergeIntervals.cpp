class Solution {
public:

    bool sorter(vector<int> const& v1, vector<int> const& v2) {
        return v1[0] < v2[0];
    }


    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) -> bool { return a[0] < b[0]; });
        ans.push_back(intervals.front());

        for (int i = 1; i < n; i++) {
            if (ans.back()[1] >= intervals[i][0]) ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            else ans.push_back(intervals[i]);
        }

        return ans;
    }
};