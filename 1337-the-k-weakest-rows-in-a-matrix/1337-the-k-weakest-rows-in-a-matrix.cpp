bool comp(pair<int,int>& a, pair<int,int>& b){
    if(a.first==b.first) return a.second>b.second;
    return a.first>b.first;
}


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size(), m=mat[0].size();
        vector<pair<int,int>> v;
        
        for(int i=0; i<n; i++){
            int cnt=0; 
            for(int j=0; j<m; j++){
                if(mat[i][j]==1) cnt++;
                else break;
            }
            v.push_back({cnt, i});
        }
        
        sort(v.begin(), v.end(), comp);
       // for(auto i: v) cout<<i.first<<" "<<i.second<<"   ";
        
        vector<int> ans;
        for(int i=n-1; i>=n-k; i--){
            ans.push_back(v[i].second); 
        }
        
        return ans;
    }
};