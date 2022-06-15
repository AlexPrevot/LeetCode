class Solution {
public:
    bool isAnagram(string& s, string& t) {
        vector<char> memS(26, 0);
        vector<char> memT(26, 0);

        for (char c : s) memS[c - 'a']++;
        for (char c : t) memT[c - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (memS[i] != memT[i]) return false;
        }

        return true;
    }
};