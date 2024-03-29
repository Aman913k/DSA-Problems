#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll maxi=*max_element(nums.begin(), nums.end());
          
        ll l=0, r=0, cnt=0, n=nums.size();
        unordered_map<ll,ll> mp;
        
        while(r<n){
            mp[nums[r]]++;
            
            while(mp[maxi]>=k){
                cnt+=(n-1)-r+1; 
                
                mp[nums[l]]--;
                l++; 
            }
            
            r++; 
        }
        
        return cnt; 
    }
};