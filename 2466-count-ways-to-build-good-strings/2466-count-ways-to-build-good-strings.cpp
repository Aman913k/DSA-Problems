int mod=(int)1e9+7; 
class Solution {
public:       
    int helper(int target, int zero, int one, vector<int> &dp){
        if(target==0) return 1;
        if(target<0) return 0;
        
        if(dp[target]!=-1) return dp[target];  
        
        long long cntzero=helper(target-zero, zero, one, dp);
        long long cntone=helper(target-one, zero, one, dp);
        
        return dp[target]=(cntzero+cntone)%mod;  
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans=0;
        vector<int> dp(high+1, -1);  
        for(int i=low; i<=high; i++){  
            ans=((ans%mod)+(helper(i, zero, one, dp))%mod)%mod;        
        }
        return ans;           
    }    
};