class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int m=trust.size();
        
        vector<int> check(n+1, 0);
        
        for(int i=0; i<m; i++){
            check[trust[i][0]]=-1;
            
            if(check[trust[i][1]]>=0) check[trust[i][1]]+=1;
        }
        for(int i=1; i<=n; i++){
            if(check[i]==n-1) return i;
        }
        
        return -1; 
    }
};