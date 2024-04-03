bool dfs(vector<vector<char>>& board, string word, vector<vector<int>>& vis, int row, int col, int indx){
    int n=board.size(), m=board[0].size();
    if(indx>=word.size()) return true; 
      
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1}; 
    
    bool isOk=false; 
    
    if(row>=n || row<0 || col>=m || col<0 || word[indx]!=board[row][col]) return false;
    
    for(int i=0; i<4; i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        
        board[row][col]='$';
        isOk=dfs(board, word, vis, nrow, ncol, indx+1)||isOk;  
    }
      
    board[row][col]=word[indx]; 
    return isOk;  

}



class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(), m=board[0].size();
                  
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){  
                if(dfs(board, word, vis, i, j, 0)) return true;
            }  
        }
        
        return false;
        
        
    }
};