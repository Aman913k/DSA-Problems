class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        auto nums=score; 
        vector<string> ans;
        int n=nums.size();  
         
        sort(nums.begin(), nums.end(), greater<int>());
        unordered_map<int,int> mp;
        
        for(int i=1; i<=n; i++){
            mp[nums[i-1]]=i;   
        }
          
        for(int i=0; i<n; i++){
            if(mp[score[i]]==1) ans.push_back("Gold Medal");
            else if(mp[score[i]]==2) ans.push_back("Silver Medal");
            else if(mp[score[i]]==3) ans.push_back("Bronze Medal");
            else ans.push_back(to_string(mp[score[i]])); 
        }
        
        return ans;
    }
};