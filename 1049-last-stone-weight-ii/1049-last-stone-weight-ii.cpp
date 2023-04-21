class Solution {
public:
    int helper(vector<int>& stones, vector<vector<int>>& dp, int indx, int s2){
        int n=stones.size();        
        if(indx==n-1){
            if(stones[indx]<=s2) return stones[indx];
            else return 0; 
        }
        if(dp[indx][s2]!=-1) return dp[indx][s2];  
        
        int take=0;
        if(stones[indx]<=s2) take=stones[indx]+helper(stones, dp, indx+1, s2-stones[indx]);
          
        int nottake=0+helper(stones, dp, indx+1, s2);  
         
        return dp[indx][s2]=max(take, nottake); 
    }  
      
    int lastStoneWeightII(vector<int>& stones) { 
        int n=stones.size();
        int totalSum=accumulate(stones.begin(), stones.end(), 0);
        int s2=totalSum/2; 
        vector<vector<int>> dp(n, vector<int>(s2+1, -1)); 
        return totalSum-2*helper(stones, dp, 0, s2); 
    }
};