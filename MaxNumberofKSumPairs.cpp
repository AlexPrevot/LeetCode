class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> needs;
        int count = 0;

        for (int val : nums) {

            if (needs[val] > 0) {
                count++;
                needs[val]--;
            }
            else needs[k - val]++;
        }

        return count;

    }
};