class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), n2=nums2.size();
        int indx=-1;
        unordered_map<int, int> mp, mp2;
        for(auto i: nums1) mp[i]++;
        for(auto i: nums2) mp2[i]++; 
        int ans=0; 
        
        for(int i=-1001; i<=1001; i++){
            int fg=0; 
            for(int j=0; j<n2; j++){
                if(mp.find(nums2[j]+i)!=mp.end() && mp[nums2[j]+i]>=mp2[nums2[j]]) continue;
                
                  
                else{
                    fg=1;
                    break;
                }
            }
            if(fg==0) ans=i;
        }
        
        return ans*-1;  
    }
};