class Solution {
public:
    void helper(int n, vector<vector<int>>& ans, vector<int>& v, int ind, int k){  
        
        if(v.size()==k){
            ans.push_back(v);
            return;  
        }
        
        for(int i=ind; i<=n; i++){
            v.push_back(i);
            helper(n, ans, v, i+1, k);
            v.pop_back();   
        }    
        
   }

    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(n, ans, v, 1, k);
        
        return ans;
    }
};