class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int n=nums.size();
        int maxi=1; 
        unordered_map<int,int> mp; 
        int mini=*min_element(nums.begin(), nums.end());
        
        
        for(auto i: nums) mp[i]++;
        if(mp[mini]==1) return 1;
        
        for(int i=0; i<n; i++) if(nums[i]%mini) return 1;           
        
        return (mp[mini]+1)/2;        
        
    }
};  