class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>> &ans, int indx, int n, vector<int> &v){
        if(indx==n){       
            ans.push_back(v);
            return;         
        }
        
        v.push_back(nums[indx]);       // take                        
        helper(nums, ans, indx+1, n, v);     
        v.pop_back();
        helper(nums, ans, indx+1, n, v);     
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int n=nums.size();
        helper(nums, ans, 0, n, v);
        return ans;  
    }
};