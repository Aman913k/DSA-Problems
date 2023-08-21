int dp[100001];
int helper(vector<pair<pair<int,int>,int>>& v, vector<int>& t, int indx){
    if(indx>=v.size()) return 0;
    if(dp[indx]!=-1) return dp[indx]; 
    
    int pick=0, nonpick=0;
    auto it=lower_bound(t.begin(), t.end(), v[indx].first.second)-t.begin();    
    pick=v[indx].second+helper(v, t, it);
    nonpick=helper(v, t, indx+1);
    
    return dp[indx]=max(pick, nonpick);   
    
}


class Solution {
public:
    int jobScheduling(vector<int>& Stime, vector<int>& Etime, vector<int>& profit) {
        vector<pair<pair<int,int>,int>> v(Stime.size());
        memset(dp,-1,sizeof (dp));
        for(int i=0; i<Stime.size(); i++){
            v[i].first.first=Stime[i];
            v[i].first.second=Etime[i];
            v[i].second=profit[i];    
        }
        
        vector<int> t;
        sort(v.begin(), v.end());
        for(auto it: v) t.push_back(it.first.first);
        
        return helper(v, t, 0);
    }
};