class Solution {
public:
    int dp[1001][1001];
    
    int helper(vector<int>& nums, int target,int prev, int indx){
        if(nums.size()==1) return 1;
      
        if(indx==nums.size()-1) {
            if(abs(nums[prev]-nums[indx])<=target) return 1;
            return -1e9;
        }
        
        if(dp[indx][prev]!=-1) return dp[indx][prev];
        
        int ans=INT_MIN;  
        if(abs(nums[prev]-nums[indx])<=target) ans=max(ans,1+helper(nums, target, indx, indx+1));
        ans=max(ans,helper(nums, target, prev, indx+1));
        
        return dp[indx][prev]=ans; 
    }
    
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        memset(dp, -1, sizeof(dp));
        
      int ans=helper(nums, target, 0, 1);
        
        if(ans<=0) return -1;
        return ans;
        
        
    }
};