int dp[1001][1001];

int helper(vector<vector<int>>& pairs, int prev, int indx){
    if(indx>=pairs.size()) return 0;
    
    if(dp[prev+1][indx]!=-1) return dp[prev+1][indx];
    
    int pick=0, nonpick=0;
    
    if(prev==-1 || pairs[indx][0]>pairs[prev][1]) pick=1+helper(pairs, indx, indx+1);
    nonpick=helper(pairs, prev, indx+1);
    
    return dp[prev+1][indx]=max(pick,nonpick);  
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp, -1, sizeof dp);  
        sort(pairs.begin(), pairs.end());
        
        return helper(pairs, -1, 0); 
    }
};