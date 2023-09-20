class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totsum=accumulate(nums.begin(), nums.end(), 0);
        
        int k=totsum-x;
        if(k<0) return -1;
        
        int maxi=-1;
        
        int l=0, r=0;
        int sum=0;
        while(r<nums.size()){
            sum+=nums[r];
             
            while(sum>k){    
                sum-=nums[l];
                l++;
            }
            
            if(sum==k) maxi=max(maxi, r-l+1); 
            r++;  
        }
        
        if(maxi==-1) return maxi; 
        return nums.size()-maxi; 
    }
};