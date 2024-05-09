#define ll long long
class Solution {
public:
    long long maximumHappinessSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>()); 
        int n=nums.size();
        int l=0; 
        ll ans=0;
        
        while(k-- && nums[l]-l>0){
            ans+=nums[l]-l;
            l++;
        }
        
        return ans; 
    }
};