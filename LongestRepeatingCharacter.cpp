class Solution {
public:

    int characterReplacement(string s, int k) {
        int n = s.size();
        int mem[26];

        for (int i = 0; i < 26; i++) mem[i] = 0;

        int left = 0;
        int right = 0;
        int ans = 0;
        int maxFreq = 0;

        while (right < n) {
            mem[s[right] - 'A']++;
            maxFreq = max(maxFreq, mem[s[right] - 'A']);

            if (right - left + 1 - maxFreq > k) {
                ans = max(ans, right - left);
                mem[s[left] - 'A']--;
                left++;
            }

            right++;
        }

        return max(ans, right - left);

    }
};