class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();  
        
       // O(M+N)  --> SC      
        
        vector<int> col(m, -1);
        vector<int> row(n, -1);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(col[j]==0 || row[i]==0) matrix[i][j]=0; 
            }
        }
        
        
    }
};