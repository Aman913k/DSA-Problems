class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums) mp[i]++;
        
        int n=0;
        for(auto i: mp) n=max(n, i.second); 
        
        vector<vector<int>> ans;
        
        for(int i=0; i<n; i++){    
            vector<int> v;
            for(auto &j: mp){  
                if(j.second){
                    v.push_back(j.first);
                    j.second--;  
                } 
            }
            ans.push_back(v);
        }
        return ans;  
    }
};