class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size(); 
        int prev=nums[n-1];  
        long long ans=0;
        
        for(int i=n-1; i>=0; i--){
            int partition=nums[i]/prev;
            if(nums[i]>prev){
                if(nums[i]%prev) partition+=1;
                prev=nums[i]/partition;
                ans+=partition-1;
                
            }
    
            else prev=nums[i];
        }
        
        return ans;
    }
};