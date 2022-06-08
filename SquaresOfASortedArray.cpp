class Solution {
public:


    vector<int> sortedSquares(vector<int>& nums)
    {
        int l = 0; //left
        int r = nums.size() - 1; //right

        vector<int> ans(nums.size());

        for (int i = nums.size() - 1; i >= 0; i--)
        {

            if (abs(nums[l]) > nums[r])
            {
                ans[i] = pow(nums.at(l), 2);
                l++;
            }
            else
            {
                ans[i] = pow(nums.at(r), 2);
                r--;
            }

        }


        return ans;
    }
};