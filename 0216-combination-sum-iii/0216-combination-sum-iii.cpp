class Solution {
public:
    void helper(int k, int n, int ind, vector<int>&v, vector<vector<int>>& ans){
        if(v.size()==k){
            if(n==0) ans.push_back(v);
            return;
        }
        
        for(int i=ind; i<=9; i++){
            if(i<=n){
                v.push_back(i);
                helper(k, n-i, i+1, v, ans);
                v.pop_back();
            }
            
        }
    }
    
    //  1 2 3 4      tar=7
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        
        helper(k, n, 1, v, ans);
        return ans;
    }
};