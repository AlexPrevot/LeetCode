class Solution {
public:
    vector<string> findRepeatedDnaSequences(string& s) {
        if (s.size() <= 10) return {};
        unordered_map<string, int> mem;


        int left = 0;
        int right = 9;

        while (right < s.size()) {
            auto curr = s.substr(left, right - left + 1);
            if (mem.find(curr) != mem.end()) mem[curr] += 1;
            else mem[curr] = 1;

            right++;
            left++;
        }

        vector<string> ans;

        for (auto& it : mem)
            if (it.second > 1) ans.push_back(it.first);

        return ans;
    }
};