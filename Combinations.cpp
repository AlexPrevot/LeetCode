class Solution {
public:
    vector<vector<int>> sol;
    
    void solve(vector<int> curr,int n, int k, int idx){
        if(curr.size() >= k){
            sol.push_back(curr);
            return;
        }
        for(int i = idx; i < n; i++){
            vector<int> new_curr = curr;
            new_curr.push_back(i + 1);
            solve(new_curr,n,k,i + 1);
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> first;
        solve(first,n,k,0);
        
        return sol;
    }
};