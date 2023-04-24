class Solution {
public:
    void helper(vector<int>& nums, int indx, set<vector<int>>& st){
        if(indx==nums.size()){
            st.insert(nums);
            return; 
        }
        
        for(int i=indx; i<nums.size(); i++){
            swap(nums[indx], nums[i]);
            helper(nums, indx+1, st);
            swap(nums[indx], nums[i]); 
        }
    }
    
       
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> st;
        helper(nums, 0, st);
        vector<vector<int>> ans;
        
        for(auto i: st) ans.push_back(i);
        return ans;  
    }
};