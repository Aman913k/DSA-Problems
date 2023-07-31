class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();  
        
       // O(M+N)  --> SC      
        
        
        vector<int> row(m, -1);
        vector<int> col(n, -1);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    row[j]=0;
                    col[i]=0;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(col[i]==0 || row[j]==0) matrix[i][j]=0; 
            }
        }
        
        
    }
};