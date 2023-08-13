int helper(vector<int>& v, int indx, vector<int>& dp){
    int n=v.size();
    if(indx==n) return 1;
    
    if(dp[indx]!=-1) return dp[indx];   
    
    if(indx+1<n && v[indx]==v[indx+1]){
        if(helper(v, indx+2, dp)) return true;     
        
        if(indx+2<n && v[indx+1]==v[indx+2])
            if(helper(v, indx+3, dp)) return true;
        
    }
    
   
    if(indx+2<n){
        if(v[indx+1]-1==v[indx] && v[indx+2]-1==v[indx+1])
            if(helper(v, indx+3, dp)) return true;  
    }
    
    
    return dp[indx]=false;  

}



class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
      
        return helper(nums, 0, dp);
    }
};