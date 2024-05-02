class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxi=-1; 
        for(auto i: nums){
            if(mp[i*-1]) maxi=max(maxi, abs(i));
            mp[i]++; 
        }
        
        return maxi; 
    }
};