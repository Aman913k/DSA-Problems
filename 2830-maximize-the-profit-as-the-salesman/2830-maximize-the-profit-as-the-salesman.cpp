int dp[100001];
bool comp(const vector<int>& a, const vector<int>& b){
    if(a[0]==b[0]) return a[1]<b[1];
    return a[0]<b[0];
}
bool comp1(const pair<int,int>& a, const pair<int,int>& b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

int helper(int n, vector<vector<int>>& offers, int indx, vector<pair<int,int>>& v){
    if(indx>=offers.size()) return 0;
    if(dp[indx]!=-1) return dp[indx];
    
    int pick=0, nonpick=0;
    pair<int,int> p={v[indx].second+1, v[indx].second+1};
    auto it=lower_bound(v.begin(), v.end(), p)-v.begin();
   // cout<<it;
    
    pick=offers[indx][2]+helper(n, offers, it, v);
    nonpick=helper(n, offers, indx+1, v);
    
    return dp[indx]=max(pick, nonpick);
    
    
}

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        memset(dp, -1, sizeof(dp));
        sort(offers.begin(), offers.end(), comp);
          
        vector<pair<int,int>> v;
        for(auto i: offers) v.push_back({i[0],i[1]});
        sort(v.begin(), v.end(), comp1);
        
        return helper(n, offers, 0, v); 
    }
};