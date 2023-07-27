class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n=nums.size();
        int l=0, r=n-1;
        int maxi=INT_MIN;
        
        while(l<r){
            int height=min(nums[l], nums[r]);
            maxi=max(maxi, height*(r-l));
            
            
            if(nums[l]<=nums[r]) l++;
            else if(nums[l]>nums[r]) r--;
            
            
        }
        return maxi;    
    }
};