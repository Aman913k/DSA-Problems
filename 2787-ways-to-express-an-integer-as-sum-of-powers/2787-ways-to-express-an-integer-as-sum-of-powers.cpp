int mod=1e9+7;
int dp[301][301];

class Solution {
public:
    int helper(int n, int x, int num){
        if(n==0) return 1;
        if(num>n) return 0;
        
        if(dp[n][num]!=-1) return dp[n][num];
        
        int temp=pow(num,x);
        if(temp>n) return 0;
        
        int pick=helper(n-temp, x, num+1);
        int nonpick=helper(n, x, num+1);
        
        return dp[n][num]=(pick%mod+nonpick%mod)%mod;  
        
    }
    
    
    
    
    int numberOfWays(int n, int x) {
        if(n==1) return 1;
        memset(dp, -1, sizeof(dp));   
        return helper(n, x, 1);  
        
    }
};