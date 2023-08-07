class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        
        int beg=0, end=m*n-1;
        
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            if(matrix[mid/m][mid%m]<target) beg=mid+1;
            else if(matrix[mid/m][mid%m]==target) return true;
            else end=mid-1;
        }
        return false; 
    }
};