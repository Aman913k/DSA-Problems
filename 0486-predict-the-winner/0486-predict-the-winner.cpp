int dp[21][21]; 

int helper(vector<int>& nums, int i, int j){
    int n=nums.size();
    
    if(i==j) return nums[i];  
    if(i>j) return 0;
    
    int aliceFirstMove=0, aliceSecondMove=0; 
    
    aliceFirstMove=nums[i]+min(helper(nums, i+2, j), helper(nums, i+1, j-1));
    aliceSecondMove=nums[j]+min(helper(nums, i+1, j-1), helper(nums, i, j-2));
    
    return dp[i][j]=max(aliceFirstMove, aliceSecondMove);
}



class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        memset(dp, -1, sizeof(dp));
        
        int total=0; 
        for(auto i:nums) total+=i;
        
        int alice=helper(nums, 0, n-1);
        //cout<<alice;
        
        if(alice>=total-alice) return true;
        
        return false;  
    }
};