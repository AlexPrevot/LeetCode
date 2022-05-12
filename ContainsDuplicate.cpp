class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> s;

        for (int val : nums) {
            if (s[val]) return true;
            s[val] = 1;
        }

        return false;
    }
};