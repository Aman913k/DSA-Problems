class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        for(int i=0; i<n; i++){
            if(grid[i][0]==0){
                for(int j=0; j<m; j++) grid[i][j]^=1;
            }
        }
          
        for(int j=0; j<m; j++){
            int cnt1=0, cnt0=0; 
            for(int i=0; i<n; i++){
                if(grid[i][j]==1) cnt1++;
                else cnt0++;  
            }
            if(cnt0>cnt1){
                for(int i=0; i<n; i++){
                    grid[i][j]^=1;
                }
            }
        }
          
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]) ans+=(1<<(m-j-1));
            }
        }
        
        return ans; 
 
    }
};