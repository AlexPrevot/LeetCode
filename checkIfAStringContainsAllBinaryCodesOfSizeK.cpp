class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int need = pow(2, k);
        bool mem[need];
        for (int i = 0; i < need; i++) mem[i] = true; // if true unused
        int mask = need - 1;
        int val = 0;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            val = ((val << 1) & mask) | (c - '0');

            if (i >= k - 1 && mem[val]) {
                mem[val] = false;
                need--;
            }

            if (!need) return true;


        }
        return false;
    }
};