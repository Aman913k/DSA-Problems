class Solution {
public:
    int dp[1001][1001];
    
    int helper(vector<int>& nums, int target,int prev, int indx){
        if(nums.size()==1) return 1;
        if(indx>=nums.size()) return -1e9;

      
        if(indx==nums.size()-1) {
            if(abs(nums[prev]-nums[indx])<=target) return 1;
            return -1e9;
        }
        
       
        
        if(dp[indx][prev]!=-1) return dp[indx][prev];
        
        int pick=-1e9, nonpick=-1e9;  
        if(abs(nums[prev]-nums[indx])<=target) pick=1+helper(nums, target, indx, indx+1);
        nonpick=0+helper(nums, target, prev, indx+1);
         
        //cout<<pick<<" "<<nonpick<<" "<<indx<<" "<<prev<<"   ";
        //cout<<max(pick, nonpick)<<" ";
        return dp[indx][prev]=max(pick, nonpick); 
    }
    
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        memset(dp, -1, sizeof(dp));
        
      int ans=helper(nums, target, 0, 1);
        cout<<endl;
        
        if(ans<=0) return -1;
        return ans;
        
        
    }
};