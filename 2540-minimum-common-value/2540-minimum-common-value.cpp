class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> seen;
        int ans=INT_MAX;
        
        for(auto i: nums1)if(!seen[i]) seen[i]=1;
        for(auto i: nums2) if(seen[i]) seen[i]+=1;
        
        int cnt=0;
        for(auto i: seen) if(i.second>=2) ans=min(ans, i.first); 
        
        if(ans==INT_MAX) return -1;
        return ans;
        
    }
};