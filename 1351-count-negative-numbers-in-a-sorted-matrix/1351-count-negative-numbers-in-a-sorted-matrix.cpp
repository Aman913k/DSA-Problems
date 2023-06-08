class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int row=n-1, col=0;
        int cnt=0;
              
        while(row>=0 && col<m){
            if(grid[row][col]<0){
                cnt+=m-col;
                row-=1;
            }
            else col+=1;      
        
        }
        return cnt;
    }
};