class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        int n = words.size();

        vector<int> mem(n);

        for (int i = 0; i < n; i++) {
            for (char& c : words[i]) mem[i] |= 1 << c - 'a';

            for (int j = 0; j < i; j++) {
                if (!(mem[i] & mem[j])) ans = max(ans, int(words[i].size() * words[j].size()));
            }
        }

        return ans;

    }
};