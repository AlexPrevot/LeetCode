class Solution {
public:
    string reverseWords(string& s) {
        int start = s.size() - 1;

        string ans = "";

        while (start > -1) {
            while (start > -1 && s[start] == ' ') start--;
            if (start == -1) break;
            int end = start;

            while (end > -1 && s[end] != ' ') end--;


            ans += s.substr(end + 1, start - end);
            ans += " ";

            start = end;
        }

        if (ans[ans.size() - 1] == ' ') ans.pop_back();


        return ans;
    }
};