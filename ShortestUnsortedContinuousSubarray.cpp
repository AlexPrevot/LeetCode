class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int bigger = INT_MIN;
        int smaller = INT_MAX;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (smaller > nums[i]) smaller = nums[i];
                if (smaller > nums[i + 1]) smaller = nums[i + 1];
                if (bigger < nums[i]) bigger = nums[i];
                if (bigger < nums[i + 1]) bigger = nums[i + 1];
            }
        }

        int idx_left = 0;
        int idx_right = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > smaller) {
                idx_left = i;
                break;
            }
        }

        for (int i = nums.size() - 1; i > -1; i--) {
            if (nums[i] < bigger) {
                idx_right = i + 1;
                break;
            }
        }


        return idx_right - idx_left;
    }
};