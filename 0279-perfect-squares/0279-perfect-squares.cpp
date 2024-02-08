class Solution {
public:
    int helper(int target, int indx, vector<int> &v, vector<vector<int>> &dp){
        if(indx==0){  
            if(target%v[indx]==0) return target/v[indx];
            else return 1e9;
        }
        if(dp[indx][target]!=-1) return dp[indx][target];  
        
        int nonpick=0+helper(target, indx-1, v, dp);
        int pick=1e9;
        if(v[indx]<=target) pick=1+helper(target-v[indx], indx, v, dp);
        
        return dp[indx][target]=min(pick, nonpick);            
    }
    
    
    
    int numSquares(int n) {
        vector<int> v;
        int k=0;
        for(int i=1; i<=n; i++){
            v.push_back(i*i);
            k=i*i;
            if(k>n) break;
        }
        int index=v.size();
        vector<vector<int>> dp(index, vector<int> (n+1,-1));
        return helper(n,index-1,v,dp);
    }
};