class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1)); 
        int tot=0;
        
        //for(int i=0; i<n; i++) dp[i][i]=1; 
        
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(i==j) dp[i][j]=1;
                else if((j-i)==1 && s[i]==s[j]) dp[i][j]=1;
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]) dp[i][j]=1;  
                    else dp[i][j]=0;
                }
                tot+=dp[i][j]; 
            }
        }
        
        return tot; 
    }
};