class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        vector<int> mem;
        unordered_map<int, int> mp;
        vector<int> ans(s1);

        for (int i = 0; i < s2; i++) {
            while (mem.size() && nums2[mem.back()] < nums2[i]) {
                mp[nums2[mem.back()]] = nums2[i];
                mem.pop_back();
            }
            mem.push_back(i);
        }

        for (int val : mem) mp[nums2[val]] = -1;
        for (int i = 0; i < s1; i++) ans[i] = mp[nums1[i]];

        return ans;
    }
};