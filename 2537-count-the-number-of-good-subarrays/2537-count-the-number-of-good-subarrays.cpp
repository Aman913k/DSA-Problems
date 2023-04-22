class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int l=0, r=0;
        int n=nums.size();
        unordered_map<int, int> mp;
        int cnt=0;
        long long ans=0;
         
        while(r<n){
            mp[nums[r]]++;
            cnt+=mp[nums[r]]-1;
            
            while(cnt>=k){
                ans+=n-r;
                mp[nums[l]]--;
                cnt-=mp[nums[l]];
                l++;  
            }  
            r++;   
        }
        return ans; 
    }
};