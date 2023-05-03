class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1, mp2;
        set<int> st1,st2; 
        
        for(auto i: nums1) mp1[i]++;
        for(auto i: nums2) mp2[i]++;
        
        for(int i=0; i<nums1.size(); i++){
            if(!mp2[nums1[i]]) st1.insert(nums1[i]);
        }
        
        for(int i=0; i<nums2.size(); i++){
            if(!mp1[nums2[i]]) st2.insert(nums2[i]);
        }
        
        vector<int> v1,v2;
        for(auto i: st1) v1.push_back(i);
        for(auto i: st2) v2.push_back(i);
        
        return {v1, v2};
            
    }
};