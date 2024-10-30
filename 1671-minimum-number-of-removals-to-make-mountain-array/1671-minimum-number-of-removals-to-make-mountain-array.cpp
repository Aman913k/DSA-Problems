int dp[1001][1001][3];

int helper(vector<int>& nums, int prev, int indx, int seenPeak){
    if(indx>=nums.size()){
        if(seenPeak==2) return 0;
        return -1e9; 
    }
    if(dp[prev+1][indx][seenPeak]!=-1) return dp[prev+1][indx][seenPeak]; 
    int pick=-1e9, nonpick=-1e9, setPeak=-1e9;
              
    if(seenPeak){
        if(nums[indx]<nums[prev]) pick=1+helper(nums, indx, indx+1, 2);   
    }
    
    
    else if(prev==-1 || (nums[indx]>nums[prev])){
        pick=1+helper(nums, indx, indx+1, 0);
        if(prev!=-1) setPeak=1+helper(nums, indx, indx+1, 1);
    }
    
    nonpick=helper(nums, prev, indx+1, seenPeak);
    
    return dp[prev+1][indx][seenPeak]=max({pick, nonpick, setPeak});
    
}



class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size(); 
        memset(dp, -1, sizeof dp); 
        
        return n-helper(nums, -1, 0, 0);
    }
};