class Solution {
public:
    unordered_map<int, string> mem = { {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };
    vector<string> sol;

    void solve(string& digits, string& curr, int idx) {
        if (idx >= digits.size()) {
            sol.push_back(curr);
            return;
        }

        char nbr = digits[idx];

        string& digits_str = mem[nbr];

        for (int i = 0; i < digits_str.size(); i++) {
            string new_curr = curr + digits_str[i];
            solve(digits, new_curr, idx + 1);
        }
    }

    vector<string> letterCombinations(string& digits) {
        if (!digits.size()) return sol;
        string empty = "";
        solve(digits, empty, 0);

        return sol;
    }
};