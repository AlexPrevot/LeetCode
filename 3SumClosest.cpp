class Solution {
public:

    int twoSumClosest(vector<int>& nums, int target, int start) {
        // /!\ considers nums already sorted
        int ans = 0;
        //int diff = INT_MAX;
        int size = nums.size();

        int left = start;
        int  right = size - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            int curr_diff = abs(target - sum);

            if (curr_diff < diff) {
                ans = sum;
                diff = curr_diff;
            }


            if (sum > target)
                right--;
            else if (sum < target) {
                left++;
            }
            else return sum;
        }

        return ans;

    }


    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int diff = INT_MAX;

        for (int i = 0; i < size - 2; i++) {
            int curr_target = target - nums[i];

            int curr = twoSumClosest(nums, curr_target, i + 1);

            int curr_diff = abs(target - curr - nums[i]);

            if (curr_diff < diff) {
                ans = nums[i] + curr;
                diff = curr_diff;
            }


        }





        return ans;
    }
};