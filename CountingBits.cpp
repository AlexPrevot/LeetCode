class Solution {
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);

        for (int i = 0; i < n + 1; i++) {
            int count = 0;
            int cpy = i;

            while (cpy) {
                count += cpy & 1;
                cpy >>= 1;
            }

            ans[i] = count;
        }

        return ans;
    }
};