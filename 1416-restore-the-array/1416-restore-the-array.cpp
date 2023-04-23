class Solution {
public:
    int mod=1e9+7;
    int helper(string& s, int k, int indx, vector<int>& dp){
        if(indx==s.size()) return 1;  
        if(dp[indx]!=-1) return dp[indx];
        if(s[indx]=='0') return 0;
        
        long long ans=0;
        long long num=0;
        
        for(int i=indx; i<s.size(); i++){
            num=(num*10)+(s[i]-'0');
            if(num>k) break;
            ans+=helper(s, k, i+1, dp);
            ans=ans%mod;
        }
        
        return dp[indx]=ans;
    }
    
     
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size()+1, -1);
        return helper(s, k, 0, dp);
    }
};