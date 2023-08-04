class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string ss=s;   
        reverse(ss.begin(), ss.end());
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int ans=0;
        
        for(int indx1=1; indx1<=n; indx1++){
            for(int indx2=1; indx2<=n; indx2++){
                if(s[indx1-1]==ss[indx2-1]) dp[indx1][indx2]=1+dp[indx1-1][indx2-1];
                else dp[indx1][indx2]=max(dp[indx1-1][indx2], dp[indx1][indx2-1]);
                
                ans=max(ans, dp[indx1][indx2]);
            }
        }
         
        return ans;          
    }
};