class Solution {
public:
    int dp[102][102][102];   
    int mod=1e9+7;
    
    int helper(int minProfit, vector<int>& group, vector<int>& profit, int i, int j, int n){    
  
        if(i==profit.size()){
            if(j>=minProfit && n>=0) return 1; 
            return 0; 
        }
        if(n<0) return 0;  
        if(dp[i][j][n]!=-1) return dp[i][j][n];
        
        int take=helper(minProfit, group, profit, i+1, min(j+profit[i], minProfit), n-group[i]);
        int nottake=helper(minProfit, group, profit, i+1, j, n);
        
        return dp[i][j][n]=(take%mod+nottake%mod)%mod;  
    } 
    
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));   
        
        return helper(minProfit, group, profit, 0, 0, n); 
    }
};