int dp[101][101];

int helper(int row, int col, int m, int n){
    if(row==0 && col==0) return 1;
    if(row<0 || col<0 || row>=m && col>=n) return 0;
    
    if(dp[row][col]!=-1) return dp[row][col]; 
    
    int up=0, left=0;
    up=helper(row-1, col, m, n);
    left=helper(row, col-1, m, n);    
    
    return dp[row][col]=up+left; 
      
}




class Solution {
public:
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof dp);
        return helper(m-1, n-1, m, n); 
    }
};