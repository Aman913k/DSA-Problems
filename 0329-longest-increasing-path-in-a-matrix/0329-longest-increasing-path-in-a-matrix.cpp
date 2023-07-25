int dp[201][201];

class Solution {
public:
    int helper(vector<vector<int>>& matrix, int n, int m, int row, int col){
        if(row<0 || col<0 || row>=n || col>=m){
            return 0;
        }
        
        if(dp[row][col]!=-1) return dp[row][col];
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
    
        int maxi=0; 
        for(int i=0; i<4; i++){
            if( (row+delrow[i]>=0 && col+delcol[i]>=0 && row+delrow[i]<n && col+delcol[i]<m) && matrix[row+delrow[i]][col+delcol[i]]>matrix[row][col] ){
                
                maxi=max(maxi,1+helper(matrix, n, m, row+delrow[i], col+delcol[i]));
                
            }
        }
        return dp[row][col]=maxi;          
    }
    
    
    
    
    
    
    
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        memset(dp, -1, sizeof(dp)); 
        
        int ans=0;   
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans=max(ans, helper(matrix, n, m, i, j));
            }
        }
        
        
        return ans+1;
    }
};