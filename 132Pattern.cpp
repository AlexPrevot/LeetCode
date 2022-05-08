class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        stack<int> mem;
        int right = INT_MIN; // the 2 from 132

        for (int i = size - 1; i > -1; i--) {
            if (nums[i] < right) return true;
            else
                while (mem.size() && nums[i] > mem.top()) {
                    right = mem.top();
                    mem.pop();
                }

            mem.push(nums[i]);
        }


        return false;
    }
};