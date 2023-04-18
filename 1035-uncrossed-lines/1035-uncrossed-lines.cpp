class Solution {
public:
    int helper(vector<int>& nums1, vector<int>& nums2, int indx1, int indx2, vector<vector<int>>& dp){
        if(indx2>=nums2.size()||indx1>=nums1.size()) return 0;
        if(dp[indx1][indx2]!=-1) return dp[indx1][indx2]; 
         
        int pick=0,nonpick=0;
        if(nums1[indx1]==nums2[indx2]) pick=1+helper(nums1, nums2, indx1+1, indx2+1, dp);
        
        else
        nonpick=max(helper(nums1, nums2, indx1+1, indx2, dp), helper(nums1, nums2, indx1, indx2+1, dp));  
        return dp[indx1][indx2]=pick+nonpick; 
    }  
    
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int indx1=0, indx2=0;
        vector<vector<int>> dp(nums1.size(), vector<int> (nums2.size(), -1));
        
        return helper(nums1, nums2, indx1, indx2, dp); 
    }
};