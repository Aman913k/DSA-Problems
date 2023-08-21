int dp[100001][2];

int helper(vector<vector<int>>& events, vector<int>& start, int indx, int E){
    if(indx>=events.size()) return 0;
    if(E>=2) return 0;
    
    if(dp[indx][E]!=-1) return dp[indx][E];   
    
    int pick=0, nonpick=0;
    auto it=upper_bound(start. begin(), start.end(), events[indx][1])-start.begin(); 
    pick=events[indx][2]+helper(events, start, it, E+1);
    
    nonpick=helper(events, start, indx+1, E);
    
    return dp[indx][E]=max(pick, nonpick);
    
    
}


class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        memset(dp, -1, sizeof dp);
        sort(events.begin(), events.end());
        
        vector<int> start;
        for(auto i: events) start.push_back(i[0]);
        
        return helper(events, start, 0, 0);   
    }
};