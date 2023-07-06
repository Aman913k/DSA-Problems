class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini=1e9;
        int l=0, r=0;
        int n=nums.size();
        int sum=0;
        
        while(r<n){
            sum+=nums[r];
            
            while(sum>=target){
                mini=min(mini, r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        if(mini==1e9) return 0;
        return mini; 
    }
};