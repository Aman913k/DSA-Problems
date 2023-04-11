class Solution {
public:
    void helper(vector<int> &nums, set<vector<int>> &st, int indx, vector<int> &v){
        if(indx==nums.size()){
            st.insert(v);
            return; 
        }
        
        v.push_back(nums[indx]);   
        helper(nums, st, indx+1, v);
        
        v.pop_back();    
        helper(nums, st, indx+1, v); 
        
    }       
    
      
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        vector<int> v;
        helper(nums, st, 0, v);
        vector<vector<int>> ans;
        
        for(auto i: st) ans.push_back(i); 
        return ans;  
    }
};