class Solution {
public:
    int helper(string &s, string &t, int indx1, int indx2, int n, vector<vector<int>>& dp){
        if(indx1>=n || indx2>=n) return 0;
        if(dp[indx1][indx2]!=-1) return dp[indx1][indx2];  
        
        //pick
        if(s[indx1]==t[indx2]) return dp[indx1][indx2]=1+helper(s, t, indx1+1, indx2+1, n, dp);
        
        return dp[indx1][indx2]=max(helper(s, t, indx1, indx2+1, n, dp), helper(s, t, indx1+1, indx2, n, dp));   
    }
    
    
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(), t.end());
        int n=s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));  
        
        return helper(s, t, 0, 0, n, dp);
    }
};