int dp[100001][123];     
class Solution {
public:
    int helper(string &s, int k, int n, int indx, char c){
        if(indx>=n) return 0;   
        if(dp[indx][c]!=-1) return dp[indx][c];  
        
        int pick=0, nonpick=0;
        
        if(c=='#') pick=1+helper(s, k, n, indx+1, s[indx]); 
        else if(abs(c-s[indx])<=k) pick=1+helper(s, k, n, indx+1, s[indx]);
        nonpick=helper(s, k, n, indx+1, c);     
        
        return dp[indx][c]=max(pick, nonpick);   
    }
    
    
    
    int longestIdealString(string s, int k) {
        int n=s.size();
        memset(dp, -1, sizeof dp);
        
        return helper(s, k, n, 0, '#');
    }
};