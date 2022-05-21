class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return 0;

        int s = 0;
        int mem = 0;

        for (int i = 0; i < size; i++) {
            s += nums[i];
            mem += nums[i] * i;
        }
        int biggest = mem;
        for (int i = size - 1; i > -1; i--) {
            mem = mem + s - (size * nums[i]);
            biggest = max(biggest, mem);
        }


        return biggest;
    }
};