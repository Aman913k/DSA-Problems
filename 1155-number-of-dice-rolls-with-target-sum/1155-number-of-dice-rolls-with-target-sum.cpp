int dp[31][1001]; 
int mod=1e9+7; 

int helper(int n, int k, int target) {
    if(n<0 || target<0) return 0;
    if(n==0 && target==0) return 1;
    
    if(dp[n][target]!=-1) return dp[n][target];
    
    int ans=0;
    for(int i=1; i<=k; i++) ans=ans%mod+helper(n-1, k, target-i)%mod;
    return dp[n][target]=ans%mod;
} 


class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof dp);  
        return helper(n, k, target);
    }
};