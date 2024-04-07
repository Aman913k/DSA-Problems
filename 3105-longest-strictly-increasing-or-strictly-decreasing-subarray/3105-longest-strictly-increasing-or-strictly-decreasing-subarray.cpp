class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=1, maxi1=1;
        int cnt=1;
         
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]) cnt++;
            else{
                maxi=max(maxi, cnt);
                cnt=1; 
            }
        }
        maxi=max(maxi, cnt);
        cnt=1;
         
        for(int i=1; i<n; i++){
            if(nums[i]<nums[i-1]) cnt++;
            else{
                maxi1=max(maxi1, cnt);
                cnt=1; 
            }
        }
        maxi1=max(maxi1, cnt);
        return max(maxi, maxi1);  
    }
};