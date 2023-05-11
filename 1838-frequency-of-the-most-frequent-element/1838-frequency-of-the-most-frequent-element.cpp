class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        long long l=0, r=0;
        int n=nums.size();
        long long sum=0;
        long long maxi=1;
        
        while(r<n){
            sum+=nums[r];
            
            if(nums[r]*(r-l+1)-sum<=k) maxi=max(maxi, r-l+1);
            else{
                sum-=nums[l];
                l++; 
            }
            r++;
        }
        return maxi;
    }
};