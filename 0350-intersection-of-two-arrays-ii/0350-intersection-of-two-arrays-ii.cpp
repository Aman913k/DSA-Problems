class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto i: nums1) mp[i]++;
        
        for(auto i: nums2){
            if(mp[i]){
                ans.push_back(i);
                mp[i]--;
            }
        }
        return ans;
    }
};