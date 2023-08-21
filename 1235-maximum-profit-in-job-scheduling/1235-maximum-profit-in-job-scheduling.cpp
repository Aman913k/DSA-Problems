int dp[100001];
int helper(vector<pair<pair<int,int>,int>>& jobs, vector<int>& start, int indx){
    if(indx>=jobs.size()) return 0;
    if(dp[indx]!=-1) return dp[indx]; 
    
    int pick=0, nonpick=0;
    auto it=lower_bound(start.begin(), start.end(), jobs[indx].first.second)-start.begin();  
    pick=jobs[indx].second+helper(jobs, start, it);
    nonpick=helper(jobs, start, indx+1);
    
    return dp[indx]=max(pick, nonpick);   
    
}


class Solution {
public:
    int jobScheduling(vector<int>& Stime, vector<int>& Etime, vector<int>& profit) {
        vector<pair<pair<int,int>,int>> jobs;
        memset(dp,-1,sizeof (dp));
        for(int i=0; i<Stime.size(); i++){
            jobs.push_back({{Stime[i], Etime[i]}, profit[i]});      
        }
        
        vector<int> start;
        sort(jobs.begin(), jobs.end());
        for(auto it: jobs) start.push_back(it.first.first);
        
        return helper(jobs, start, 0);
    }
};