class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if (n == 1) return false;

        multimap<int, int> mm;
        for (int i = 0; i < n; i++) mm.insert({ nums[i],i });

        multimap<int, int>::iterator it, itnext;

        for (it = mm.begin(); it != mm.end(); it++) {
            itnext = it;
            while (true) {
                itnext++;
                if (itnext == mm.end()) break;
                double a = (double)it->first;
                double b = (double)itnext->first;

                if (abs(b - a) <= t) {
                    if (abs((double)it->second - (double)itnext->second) <= k) return true;
                }
                else break;

            }

        }

        return false;
    }
};