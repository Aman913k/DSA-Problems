class Solution {
public:
    int helper(int indx, vector<int> &dp){
        if(indx==0) return 1;
        if(indx<0) return 0;
        
        if(dp[indx]!=-1) return dp[indx];  
        
        return dp[indx]=helper(indx-1, dp)+helper(indx-2, dp);   
    }
    
    
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp); 
    }
};