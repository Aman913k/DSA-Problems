class Solution {
public:
    int minOperations(vector<int>& nums) {
        int prev=nums[0];
        
        int ans=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<=prev){
                int toAdd=prev-nums[i]+1; 
                ans+=toAdd;
                prev=nums[i]+toAdd;
            }
            else prev=nums[i];        
        }
        
        return ans;      
    }
};