class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();   
        int ans=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int cnt=4;
                if(grid[i][j] && j-1>=0 && grid[i][j-1]) cnt--;         
                if(grid[i][j] && j+1<m && grid[i][j+1]) cnt--;
                if(grid[i][j] && i+1<n && grid[i+1][j]) cnt--;
                if(grid[i][j] && i-1>=0 && grid[i-1][j]) cnt--;
                
                if(grid[i][j]) ans+=cnt;                    
            }
        }
        return ans;
    }
};