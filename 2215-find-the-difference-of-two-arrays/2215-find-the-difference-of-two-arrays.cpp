class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1(nums1.begin(), nums1.end());
        set<int> st2(nums2.begin(), nums2.end());
        
        vector<int> v1,v2;
          
        for(auto num: st1){    
            if(!st2.count(num)>0) v1.push_back(num);  
        } 
        for(auto num: st2){    
            if(!st1.count(num)>0) v2.push_back(num);
        }               
          
        return {v1,v2};     
    }
};