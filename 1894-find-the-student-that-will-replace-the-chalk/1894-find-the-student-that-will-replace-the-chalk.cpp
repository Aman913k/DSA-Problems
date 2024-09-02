#define ll long long
class Solution {
public:
    int chalkReplacer(vector<int>& nums, int k) {
        ll sum=0;
        int n=nums.size(); 
        for(auto i: nums) sum+=i;
        
        k=k%sum; 
        
        for(int i=0; i<n; i++){
            if(nums[i]>k) return i;
            k-=nums[i];
        }
        return 0; 
    }
};