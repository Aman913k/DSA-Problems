class Solution {
public:
    void helper(vector<int>& nums, int indx, vector<vector<int>>& ans){
        
        if(indx==nums.size()){
            ans.push_back(nums);
            return;  
        }
        
          
        for(int i=indx; i<nums.size(); i++){
            swap(nums[indx], nums[i]);
            helper(nums, indx+1, ans);
            swap(nums[indx], nums[i]);
        }
    }
    
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;    
        helper(nums, 0, ans);
        return ans; 
    }
};