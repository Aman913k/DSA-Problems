class Solution {
public:
    void generateN(int n, vector<int>& ans){
        long long p=n-1;
        long long k=n-1;
        
        for(int i=1; i<n-1; i++){ 
            ans[i]=p/i;
            k-=1;
            p=ans[i]*(k);    
        } 
    }
    
    
    
    
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 1);    
        generateN(rowIndex+1, ans);
         
        return ans;
    }
};