class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans(nums.size());
        int count = 0;

        int right = nums.size() - 1;
        int left = 0;

        while (left < right) {
            if (!(nums[left] % 2))
                left++;
            else if (nums[right] % 2)
                right--;
            else {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }

        }



        return nums;
    }
};