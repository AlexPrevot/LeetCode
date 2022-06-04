class Solution {
public:

    string getInside(string& s, int& idx, int& nbr) {
        int k = 0;
        int mem = idx;
        string res;
        while (s[idx] != '[') idx++;
        k = stoi(s.substr(mem, idx - mem));

        int count = 1;
        idx++;
        while (count > 0) {
            res.push_back(s[idx]);
            idx++;

            if (s[idx] == '[') count++;
            if (s[idx] == ']') count--;
        }

        nbr = k;

        return res;

    }

    string decodeString(string s) {
        string res;

        int idx = 0;
        while (idx < s.size()) {
            if (s[idx] >= 'a' && s[idx] <= 'z') res.push_back(s[idx]);
            else {
                int k;
                string inside = decodeString(getInside(s, idx, k));
                while (k--) res += inside;
            }

            idx++;
        }


        return res;
    }
};