class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto i: nums) mp[i]++;
        int miss=0;
        
        for(int i=1; i<=n; i++){
            if(mp[i]==2) ans.push_back(i);
            if(mp[i]==0) miss=i; 
        }
      
        ans.push_back(miss);   
        return ans;   
    }
};