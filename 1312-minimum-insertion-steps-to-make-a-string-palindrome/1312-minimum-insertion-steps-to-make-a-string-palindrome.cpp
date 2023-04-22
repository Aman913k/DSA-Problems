class Solution {
public:
    int helper(string& s, string& s1, int indx1, int indx2, vector<vector<int>>& dp, int n){
        if(indx1==n || indx2==n) return 0;
        if(dp[indx1][indx2]!=-1) return dp[indx1][indx2]; 
        

        if(s[indx1]==s1[indx2]) return dp[indx1][indx2]=1+helper(s, s1, indx1+1, indx2+1, dp, n);
        return dp[indx1][indx2]=max(helper(s, s1, indx1+1, indx2, dp, n), helper(s, s1, indx1, indx2+1, dp, n));
      
    }
    
    
    
    int minInsertions(string s) {  
        string s1=s; 
        reverse(s1.begin(), s1.end());
        int n=s.size(); 
        vector<vector<int>> dp(n, vector<int>(n,-1));  
        
        return s.size()-(helper(s, s1, 0, 0, dp, n));
    }
};