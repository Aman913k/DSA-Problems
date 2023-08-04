int dp[501][501];


int helper(string& s, string& t, int indx1, int indx2, int n){
    if(indx1>=n || indx2>=n) return 0;
    if(dp[indx1][indx2]!=-1) return dp[indx1][indx2];
    
    if(s[indx1]==t[indx2]) return dp[indx1][indx2]=1+helper(s, t, indx1+1, indx2+1, n);
    
    return dp[indx1][indx2]=max(helper(s, t, indx1+1, indx2, n), helper(s, t, indx1, indx2+1, n));
}

class Solution {     
public:
    int minInsertions(string s) {
        int n=s.size();
        
        string t=s;
        reverse(t.begin(), t.end());
        
        memset(dp, -1, sizeof(dp)); 
        return n-helper(s, t, 0, 0, n);
    }
};