class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> evenIdx(rowIndex + 1);
        vector<int> oddIdx(rowIndex + 1);
        
        evenIdx[0] = 1;
        oddIdx[0] = 1;
        
        vector<int>* last = &oddIdx;
        vector<int>* curr = &evenIdx;
        
        for(int i = 1; i < rowIndex + 1; i++){
            swap(last,curr);
            
            for(int j = 1; j <= i; j++)
                (*curr)[j] = (*last)[j] + (*last)[j-1];   
        }
        
        return *curr;
    }
};