class Solution {
public:
    
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int> (n,0));
        int sum=0;
        
        for(int diff=0; diff<n; diff++){
            for(int indx1=0, indx2=diff+indx1; indx2<n; indx1++, indx2++){
                if(indx1==indx2) dp[indx1][indx2]=1;
                
                else if(diff==1){
                    if(s[indx1]==s[indx2]) dp[indx1][indx2]=1;
                    else dp[indx1][indx2]=0;
                }
                
                else{
                    if(s[indx1]==s[indx2] && dp[indx1+1][indx2-1]) dp[indx1][indx2]=1;
                    else dp[indx1][indx2]=0;
                }
                
                sum+=dp[indx1][indx2];
            }
        }
        return sum;  
    }
};