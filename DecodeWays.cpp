class Solution {
public:
    int numDecodings(string& s) {
        int n = s.size(), prev = 1, prev2 = 0;

        for (int i = n - 1; i > -1; i--) {
            int curr = 0;
            if (s[i] != '0') curr += prev;
            if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) curr += prev2;

            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};