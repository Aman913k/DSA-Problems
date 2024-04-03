#define ll long long
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        ll l=1, r=1;   
        ll n=nums.size();
        ll cnt=1, ans=0;   
        
        
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[i-1]) cnt++;
            else{
                ans+=(cnt*(cnt-1))/2;
                cnt=1;
            }
        }
        
        ans+=(cnt*(cnt-1))/2;
        return ans+n;           
        
        
    }
};