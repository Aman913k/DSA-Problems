class Solution {
public:
    
    int helper(vector<int>& nums, int indx, vector<int>& dp){
        int n=nums.size();
        
        if(indx>=n-1) return 0;
        if(indx==n-1) return 1;
        
        if(dp[indx]!=1e4) return dp[indx];
 
        int ans=1e9;
        
        for(int i=1; i<=nums[indx]; i++){
            ans=min(ans, 1+helper(nums, i+indx ,dp));
        }
       
        return dp[indx]=ans;
         
    }
    
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1, 1e4);
        
       return helper(nums, 0, dp);
        
        
       
        
    }
};