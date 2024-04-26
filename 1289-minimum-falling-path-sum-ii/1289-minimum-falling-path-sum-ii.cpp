int dp[201][201];

class Solution {
public:
    int helper(vector<vector<int>>& grid, int n, int row, int col){
        if(row>=n) return 0;   
        
        if(dp[row][col]!=-1) return dp[row][col];   
        
        int ans=INT_MAX;     
        for(int j=0; j<n; j++){
            if(col==j) continue; 
                 
            int tot=grid[row][col]+helper(grid, n, row+1, j);
            ans=min(ans, tot);
        }
        
        return dp[row][col]=ans;
    }

    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        memset(dp, -1, sizeof dp); 
        int ans=INT_MAX;
        
        if(n==1) return grid[0][0]; 
        
        for(int j=0; j<n; j++){
            ans=min(ans, helper(grid, n, 0, j));
        }
        
        return ans; 
    }
};