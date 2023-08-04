int helper(string& s1, string& s2, int indx1, int indx2, int n, vector<vector<int>>& dp){
    if(indx1<0 || indx2<0) return 0;
    if(dp[indx1][indx2]!=-1) return dp[indx1][indx2];
    
    int pick=0, nonpick=0;
    
    if(s1[indx1]==s2[indx2]) pick=1+helper(s1, s2, indx1-1, indx2-1, n, dp);
    
    nonpick=0+max(helper(s1, s2, indx1-1, indx2, n, dp), helper(s1, s2, indx1, indx2-1, n, dp));
    
    return dp[indx1][indx2]=max(pick, nonpick);
    
}     






class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string ss=s;
        reverse(ss.begin(), ss.end());
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return helper(s, ss, n-1, n-1, n, dp);          
    }
};