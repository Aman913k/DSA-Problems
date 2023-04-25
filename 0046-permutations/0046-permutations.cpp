class Solution {
public:
    void helper(vector<int>& nums, unordered_map<int,int>& mp, vector<vector<int>>& ans, vector<int>& v){
        if(v.size()==nums.size()){
            ans.push_back(v);
            return;  
        }
        
        for(int i=0; i<nums.size(); i++){
            if(mp[nums[i]]==0){
                mp[nums[i]]=1;
                v.push_back(nums[i]);
                helper(nums, mp, ans, v);
                v.pop_back();
                mp[nums[i]]=0;
            }   
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<vector<int>> ans;
        vector<int> v;
        
        helper(nums, mp ,ans, v);
        return ans; 
    }
};