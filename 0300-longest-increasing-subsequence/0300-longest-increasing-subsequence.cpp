class Solution {
public:
    int helper(vector<int>& nums,int n, int indx, vector<vector<int>>& dp, int lastIndx){
        if(indx>=n) return 0;     
        if(dp[indx][lastIndx+1]!=-1) return dp[indx][lastIndx+1];
    
        int pick=0;
        if(lastIndx==-1 || nums[indx]>nums[lastIndx]) pick=1+helper(nums, n, indx+1, dp, indx);
        int nonpick=0+helper(nums, n, indx+1, dp, lastIndx); 
        
        return dp[indx][lastIndx+1]=max(pick,nonpick); 
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return helper(nums,n,0,dp,-1);
    }
};