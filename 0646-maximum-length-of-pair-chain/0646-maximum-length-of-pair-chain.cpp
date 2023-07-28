int dp[1001][1001];
bool comp(const vector<int>& a, const vector<int>& b){
    return a[0]<b[0];  
}


int helper(vector<vector<int>>& pairs, int prev, int indx){
    if(indx>=pairs.size()) return 0; 
    if(dp[indx][prev+1]!=-1) return dp[indx][prev+1];
    
    int pick=0, nonpick=0;
    if(prev==-1 || pairs[indx][0]>pairs[prev][1]) pick=1+helper(pairs, indx, indx+1);
    nonpick=0+helper(pairs, prev, indx+1);
    
    return dp[indx][prev+1]=max(pick, nonpick);          
      
}


class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp, -1, sizeof(dp)); 
        sort(pairs.begin(), pairs.end(), comp);
        
        return helper(pairs, -1, 0);
    }
};