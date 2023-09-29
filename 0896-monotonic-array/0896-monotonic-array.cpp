class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()==1) return true;
        int inc=0, dec=0;
        int n=nums.size(); 
        
        for(int i=1; i<n; i++){
            if(nums[i]<nums[i-1]){
                inc=1;
                break;
            }
        }
        
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]){
                dec=1;
                break;
            }
        }
        
        if(inc==0 || dec==0) return true;
        return false; 
        
        
    }
};