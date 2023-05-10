class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int> (n,0));
        
        int top=0, left=0, right=n-1, down=n-1;          
        int val=1;
        
        while(left<=right && top<=down && val<=n*n){
            
            for(int i=left; i<=right; i++){
                matrix[top][i]=val;
                val++;          
            }
            top++;
            
            for(int i=top; i<=down; i++){
                matrix[i][right]=val;
                val++;                
            }
            right--;
            
            if(top<=down){
                for(int i=right; i>=left; i--){
                    matrix[down][i]=val;
                    val++;     
                }
                down--;
            }
            
            if(left<=right){
                for(int i=down; i>=top; i--){
                    matrix[i][left]=val;
                    val++;     
                }
                left++;
            }
        }
        
        return matrix;     
    }
};