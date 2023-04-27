class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt0=0;
        int l=0, r=0;
        int n=nums.size();  
        int ans=0; 
        
        while(r<n){  
            if(nums[r]==0) cnt0++;
            
            while(cnt0>k){ 
                if(nums[l]==0) cnt0--;
                l++;         
            }
            r++;
            ans=max(ans, r-l+1);
        }      
        
        return ans-1;  
    }
};