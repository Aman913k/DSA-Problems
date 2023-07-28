int dp[100001][3];        

int helper(vector<int>& nums1, vector<int>& nums2, int indx, int fromArr){
    int n=nums1.size();
    
    if(indx>=n) return 0;  
    
    if(fromArr==0){
        return max({1+helper(nums1, nums2, indx+1, 1), 1+helper(nums1, nums2, indx+1, 2), helper(nums1, nums2, indx+1, 0)});  
    }
    
    if(dp[indx][fromArr]!=-1) return dp[indx][fromArr];
    
    int maxi=0;
    
    if(fromArr==1){
        if(nums1[indx]>=nums1[indx-1]) maxi=max(maxi,1+helper(nums1, nums2, indx+1, 1));
        if(nums2[indx]>=nums1[indx-1]) maxi=max(maxi,1+helper(nums1, nums2, indx+1, 2));
        
    }     
    
    if(fromArr==2){
        if(nums2[indx]>=nums2[indx-1]) maxi=max(maxi,1+helper(nums1, nums2, indx+1, 2));
        if(nums1[indx]>=nums2[indx-1]) maxi=max(maxi,1+helper(nums1, nums2, indx+1, 1));
        
    }     
    
    return dp[indx][fromArr]=maxi;          
    
}

  
class Solution {  
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        memset(dp, -1, sizeof(dp));  
        
        return helper(nums1, nums2, 0, 0);
    }
};