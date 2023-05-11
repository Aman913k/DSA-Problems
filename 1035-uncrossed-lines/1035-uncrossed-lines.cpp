class Solution {
public:
    int helper(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp, int indx1, int indx2){
        int n=nums1.size(), m=nums2.size();
        if(indx1>=n || indx2>=m) return 0;
        
        if(dp[indx1][indx2]!=-1) return dp[indx1][indx2];
        
        if(nums1[indx1]==nums2[indx2]) return dp[indx1][indx2]=1+helper(nums1,nums2,dp,indx1+1,indx2+1);
        
        return dp[indx1][indx2]=max(helper(nums1,nums2,dp,indx1+1,indx2), helper(nums1,nums2,dp,indx1,indx2+1)); 
    }
    
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(nums1, nums2, dp, 0, 0);     
    }
};