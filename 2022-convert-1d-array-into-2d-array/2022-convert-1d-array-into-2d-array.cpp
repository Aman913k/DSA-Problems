class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& nums, int m, int n) {
        int sz=nums.size();
        
        if(n*m!=sz) return {};
        vector<vector<int>> vec(m, vector<int>(n));
        int k=0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                vec[i][j]=nums[k++];
            }
        }
        
        return vec; 
    }
};