
int mod=1e9+7;
int dp[51][51][51]; 
class Solution {
public:
    int helper(int m, int n, int maxM, int row, int col){
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};  
        
        if(maxM<0) return 0; 
        
        if(row<0||row>=m||col<0||col>=n){         //   BASE CASE 
            if(maxM>=0) return 1;
            return 0;
        }
        
        if(dp[maxM][row][col]!=-1) return dp[maxM][row][col];
        int ways=0;
        for(int i=0; i<4; i++){
            ways=(ways%mod+helper(m, n, maxM-1, row+delrow[i], col+delcol[i])%mod)%mod;
        }
        
        return dp[maxM][row][col]=ways%mod;   
        
    }
    
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof dp);
        return helper(m, n , maxMove, startRow, startColumn)%mod;
        
    }
};