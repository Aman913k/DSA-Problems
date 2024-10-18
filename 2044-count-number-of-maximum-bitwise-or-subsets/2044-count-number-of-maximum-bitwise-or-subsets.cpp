#define ll long long
class Solution {
public:
    ll helper(vector<int>& nums, ll tar, int indx, int taken){
        if(indx>=nums.size()){
            if(taken==tar) return 1;   
            return 0;  
        }
        
        ll pick=0, nonpick=0;  
        
        pick=helper(nums, tar, indx+1, (taken|nums[indx]));
        nonpick=helper(nums, tar, indx+1, taken);
        
        return pick+nonpick;
    }
    
    
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size(); 
        ll orr=0;
        for(auto x: nums) orr|=x; 
        
        return helper(nums, orr, 0, 0); 
    }
};