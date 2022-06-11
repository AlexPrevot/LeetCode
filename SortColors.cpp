class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int mem[3];
        mem[0] = 0;
        mem[1] = 0;
        mem[2] = 0;

        for (int i : nums) mem[i]++;

        for (int i = 0; i < n; i++) {
            if (mem[0]-- > 0) nums[i] = 0;
            else if (mem[1]-- > 0) nums[i] = 1;
            else {
                mem[2]--;
                nums[i] = 2;
            }
        }

    }
};