class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = nums.size();
        int left = 0;
        int right = s - 1;

        int start = 0;

        if (nums[right] < nums[left]) {
            while (left < right) {
                start = left + max((right - left) / 2, 1);
                if (nums[start] < nums[left] && nums[start] < nums[right]) right = start;
                else left = start;
            }
        }

        if (target > nums.back()) {
            left = 0;
            right = start;
        }
        else {
            left = start;
            right = s - 1;
        }


        while (left <= right) {
            start = left + (right - left) / 2;
            if (target < nums[start]) right = start - 1;
            else if (target > nums[start]) left = start + 1;
            else return start;
        }


        return -1;


    }
};