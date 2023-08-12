int dp[101][101];

int helper(vector<vector<int>>& obstacleGrid, int i, int j, int n, int m){
    if(i>=n || j>=m) return 0;
    if(i==n-1 && j==m-1){
        if(obstacleGrid[i][j]==0) return 1;
        return 0;
    }
 
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int right=0, down=0;
    
    
    if(i<n && j<m && obstacleGrid[i][j]==0){
        right=helper(obstacleGrid, i, j+1, n, m);
        down=helper(obstacleGrid, i+1, j, n, m);
    }
    
    return dp[i][j]=right+down;
    
    
}


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof(dp));
        int n=obstacleGrid.size(), m=obstacleGrid[0].size(); 
        int ans=helper(obstacleGrid, 0, 0, n, m);
        
        if(n==1 && m==1) return obstacleGrid[0][0]==0;    // EDGE CASE
        return ans;  
    }
};