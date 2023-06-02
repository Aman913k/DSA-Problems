class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int fg=0;
        int n=nums.size();
        
        for(int i=1; i<n; i++){
            if(nums[i-1]<=nums[i]) continue;
            else fg=1;
        }
        
        int fg2=0;  
        if(fg==1){
            for(int i=1; i<n; i++){
                if(nums[i-1]>=nums[i]) continue;
                else fg2=1;
            }
        }
        if(fg==1 && fg2==1) return false;
        return true;
    }
};