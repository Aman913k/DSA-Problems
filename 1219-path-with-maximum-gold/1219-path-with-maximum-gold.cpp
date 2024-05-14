class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col){
        int n=grid.size(), m=grid[0].size();
        
        int gold=grid[row][col]; 
        grid[row][col]=0; 
        int mx=0;
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        for(int i=0; i<4; i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]){
                mx=max(mx, grid[nrow][ncol]+dfs(grid, nrow, ncol));
            }      
        }
        grid[row][col]=gold;
        return mx;
        
    }
    
    
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int maxi=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                maxi=max(maxi, grid[i][j]+dfs(grid, i, j));
            }  
        }
        
        return maxi; 
    }
};