class Solution {
public:
    vector<string> ans;

    void solve(string& s, int left, int right, int n) {
        if (left == n && right == n) {
            ans.push_back(s);
            return;
        }


        if (left < n) {
            string s1 = s;
            s1.push_back('(');
            solve(s1, left + 1, right, n);
        }

        if (right < left) {
            string s2 = s;
            s2.push_back(')');
            solve(s2, left, right + 1, n);
        }

    }

    vector<string> generateParenthesis(int n) {
        string first_elem = "";

        solve(first_elem, 0, 0, n);


        return ans;
    }
};