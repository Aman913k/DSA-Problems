int dp[1001]; 

int helper(vector<int>& cost, int indx){
    if(indx>=cost.size()) return 0;
    if(dp[indx]!=-1) return dp[indx]; 
    
    int stepOne=cost[indx]+helper(cost, indx+1);
    int stepTwo=cost[indx]+helper(cost, indx+2);
    
    return dp[indx]=min(stepOne, stepTwo); 
}



class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof dp);
         
        return min(helper(cost, 0), helper(cost, 1));  
    }
};