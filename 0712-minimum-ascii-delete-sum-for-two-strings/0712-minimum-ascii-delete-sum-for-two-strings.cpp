int dp[1001][1001];

int helper(string& s1, string& s2, int n, int m, int indx1, int indx2){
    if(indx1>=n && indx2>=m) return 0;
    
    if(indx1>=n && indx2<m){
        int sum=0;
        for(int i=indx2; i<m; i++) sum+=s2[i]-0;
        return sum;   
    }
    
    if(indx1<n && indx2>=m){
        int sum=0;
        for(int i=indx1; i<n; i++) sum+=s1[i]-0;
        return sum;
    }
    
    if(dp[indx1][indx2]!=-1) return dp[indx1][indx2];   
    
    
    int pick=INT_MAX, nonpick=INT_MAX, np1=0, np2=0;          
    if(s1[indx1]==s2[indx2]){
        pick=0+helper(s1, s2, n, m , indx1+1, indx2+1);
    }
    
    else nonpick=min((s1[indx1]-0)+helper(s1, s2, n, m , indx1+1, indx2), (s2[indx2]-0)+helper(s1, s2, n, m, indx1, indx2+1));
    
    
    
    return dp[indx1][indx2]=min(pick,nonpick);   
    
}
    

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(), m=s2.size();
        
        memset(dp, -1, sizeof(dp));  
        return helper(s1, s2, n, m ,0, 0); 
        
        
    }
};