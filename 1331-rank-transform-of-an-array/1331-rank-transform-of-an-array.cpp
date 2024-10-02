class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>ans(arr.size());
        set<int> st(arr.begin(),arr.end());
        
        unordered_map<int,int> mp;
        int rank=1;
        
        for(auto i: st) mp[i]=rank++;
        for(int i=0; i<arr.size(); i++){
            ans[i]=mp[arr[i]];
        }
        return ans;
    }
};