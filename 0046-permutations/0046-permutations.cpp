unordered_map<int, int> mp;
class Solution {
public:
    void helper(vector<int>& nums, vector<int>& v, vector<vector<int>>& ans, int indx){
        if(v.size()==nums.size()){
            ans.push_back(v);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(!mp[nums[i]]){
                v.push_back(nums[i]);
                mp[nums[i]]++;
                helper(nums, v, ans, i+1);
                mp[nums[i]]--;
                v.pop_back();
            }
            
        }
        
        
    }
    
    
    
    
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        
        helper(nums, v, ans, 0);
        return ans;
    }
};