int helper(vector<vector<int>>& events, vector<int>& start, int indx, int k, vector<vector<int>>& dp){
    if(indx>=events.size()) return 0;
    if(k==0) return 0;
    
    if(dp[indx][k]!=-1) return dp[indx][k];   
    
    int pick=0, nonpick=0;
    auto it=upper_bound(start. begin(), start.end(), events[indx][1])-start.begin(); 
    pick=events[indx][2]+helper(events, start, it, k-1, dp);
    
    nonpick=helper(events, start, indx+1, k, dp);
    
    return dp[indx][k]=max(pick, nonpick);
    
    
}


class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        vector<vector<int>> dp(events.size()+1, vector<int>(k+1, -1));     
        sort(events.begin(), events.end());
        
        vector<int> start;
        for(auto i: events) start.push_back(i[0]);
        
        return helper(events, start, 0, k, dp);   
    }
};