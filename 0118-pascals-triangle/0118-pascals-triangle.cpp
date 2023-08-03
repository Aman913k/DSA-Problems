void printN(int n, vector<vector<int>>& ans){
    vector<int> v(n, 1);  
    long long p=n-1;
    long long k=n-1;
    
    for(int i=1; i<n-1; i++){ 
        v[i]=p/i;
        k-=1;
        p=v[i]*(k);
    }
    ans.push_back(v); 
}          



class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i=1; i<=numRows; i++){
            printN(i, ans); 
        }
        return ans; 
    }
};