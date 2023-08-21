long long dp[100001];

long long helper(vector<vector<int>>& rides, vector<int>& start, int indx){
    if(indx>=rides.size()) return 0;
    if(dp[indx]!=-1) return dp[indx];
    
    auto it=lower_bound(start.begin(), start.end(), rides[indx][1])-start.begin();
    long long pick=0, nonpick=0;
    
    pick=rides[indx][1]-rides[indx][0]+rides[indx][2]+helper(rides, start, it);
    nonpick=helper(rides, start, indx+1);
    
    return dp[indx]=max(pick, nonpick);
}



class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        memset(dp, -1, sizeof dp);
        
        vector<int> start;
        for(auto i: rides) start.push_back(i[0]);
        sort(start.begin(), start.end());
        
        return helper(rides, start, 0);
    }
};