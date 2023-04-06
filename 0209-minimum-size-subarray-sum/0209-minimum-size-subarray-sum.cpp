class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=0, n=nums.size();
        int sum=0;
        int ans=1e9;      
        
        while(r<n){
            sum+=nums[r]; 
            
            while(sum>=target){
                sum-=nums[l];
                ans=min(ans, r-l+1);
                l++;
            }
             
            r++;
        }
        return (ans==1e9)?0 :ans ;   
    }
};