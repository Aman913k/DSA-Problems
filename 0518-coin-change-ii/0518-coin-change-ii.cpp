int dp[5001][301];


int helper(int amount, vector<int>& coins, int indx){
    if(indx>=coins.size()) return 0;
    if(amount==0) return 1;
   
    
    if(dp[amount][indx]!=-1) return dp[amount][indx];
    
    int pick=0, nonpick=0;
    if(coins[indx]<=amount) pick=helper(amount-coins[indx], coins, indx);
    nonpick=helper(amount, coins, indx+1);
    
    
    return dp[amount][indx]=pick+nonpick;
}






class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        memset(dp, -1, sizeof(dp));
        
        return helper(amount, coins, 0);
    }
};