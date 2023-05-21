class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col){
       
        grid[row][col]=2;
        int n=grid.size(), m=grid[0].size();
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        for(int i=0; i<4; i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1) dfs(grid, nrow, ncol);  
            
        }
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        int n=grid.size(), m=grid[0].size();
        int r=-1, c=-1;
        int fg=0;
        vector<vector<int>> vis(n, vector<int>(m, 0));     
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    r=i;
                    c=j;
                    break;
                }  
            }
            if(r!=-1&&c!=-1){
                dfs(grid, r, c);
                break;  
            }   
        }
        
        queue<pair<pair<int,int>, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2) q.push({{i, j}, 0});
            }
        }
        
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dist=q.front().second;
            
            q.pop(); 
            
            for(int i=0; i<4; i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    if(grid[nrow][ncol]==0){
                        grid[nrow][ncol]=2;
                        q.push({{nrow, ncol}, dist+1});
                    }
                    else if(grid[nrow][ncol]==1) return dist;
                }
            }
        }
        return 0;
        
    }
};