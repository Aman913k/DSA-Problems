class Solution {
public:
    int helper(vector<vector<int>>& piles, int k, int indx, int n, vector<vector<int>>& dp){
        if(k<=0 || indx>=n) return 0;
        if(dp[indx][k]!=-1) return dp[indx][k];  
        // not take
        int res=helper(piles, k, indx+1, n, dp);
        
        // take  
        int pick=0;
        for(int i=0; i<piles[indx].size()&&i<k; i++){
            pick+=piles[indx][i];
            res=max(res, helper(piles, k-i-1, indx+1, n, dp)+pick);
        }
        
        return dp[indx][k]=res;
        
    }
    
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
        return helper(piles, k, 0, n, dp);
    }
};