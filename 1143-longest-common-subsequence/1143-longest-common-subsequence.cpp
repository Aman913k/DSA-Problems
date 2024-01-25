class Solution {
public:
    int helper(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int match=0;
        if(text1[i]==text2[j]) match=1+helper(text1,text2,i-1,j-1,dp);
        
        int notmatch=0+max(helper(text1,text2,i-1,j,dp), helper(text1,text2,i,j-1,dp));
        
        return dp[i][j]=max(match, notmatch);
        
    }   
    
    
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return helper(text1, text2, n-1, m-1, dp); 
    }
};