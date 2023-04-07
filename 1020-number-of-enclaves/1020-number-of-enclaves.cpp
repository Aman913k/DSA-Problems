class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col){
        int n=grid.size(), m=grid[0].size(); 
        vis[row][col]=1;
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        for(int i=0; i<4; i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];  
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfs(grid, vis, nrow, ncol);  
            }
        }
    }
    
    
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==1){
                        dfs(grid, vis, i, j);
                    }
                }
            }
        }
        
        int cnt=0;      
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};