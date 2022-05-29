class Solution {
public:

    bool solve(vector<int>& mem, string& s1, string& s2, string& s3, int idxL, int idxR, int idx3) {
        if (idxL >= s1.size() && idxR >= s2.size()) return true;

        if (mem[idx3] > -1) return mem[idx3];

        bool res = false;

        if (idxL < s1.size() && s1[idxL] == s3[idx3]) res = solve(mem, s1, s2, s3, idxL + 1, idxR, idx3 + 1);
        if (idxR < s2.size() && s2[idxR] == s3[idx3]) res = res || solve(mem, s1, s2, s3, idxL, idxR + 1, idx3 + 1);

        mem[idx3] = res;

        return res;
    }

    bool isInterleave(string& s1, string& s2, string& s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        //vector<vector<int>> mem(s1.size() + 1, vector<int>(s2.size() + 1,-1));
        vector<int> mem(s3.size(), -1);


        return solve(mem, s1, s2, s3, 0, 0, 0);;
    }
};