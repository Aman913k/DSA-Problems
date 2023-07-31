int dp[501][501];

int LCS(string& word1, string& word2, int n, int m, int indx1, int indx2){
    if(indx1==n) return m-indx2;
    if(indx2==m) return n-indx1; 
    
    if(dp[indx1][indx2]!=-1) return dp[indx1][indx2]; 
    
    int ans=INT_MAX, insert=INT_MAX, replace=INT_MAX, Delete=INT_MAX;      
       
    if(word1[indx1]==word2[indx2]) ans=LCS(word1, word2, n, m, indx1+1, indx2+1);
    else{   
        insert=1+LCS(word1, word2, n, m, indx1, indx2+1);
        replace=1+LCS(word1, word2, n, m, indx1+1, indx2+1);
        Delete=1+LCS(word1, word2, n, m, indx1+1, indx2);
    }
    
    return dp[indx1][indx2]=min({ans, insert, replace, Delete});                     
} 

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        memset(dp, -1, sizeof(dp));          
        int n=word1.size(), m=word2.size();    
        
        return LCS(word1, word2, n, m, 0, 0);
               
    }
};