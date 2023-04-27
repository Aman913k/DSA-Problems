class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0, r=0;
        int n=nums.size();
        int cnt=0;
        int maxi=0; 
        
        while(r<n){
            if(nums[r]==0) cnt++;
            
            while(cnt>1){  
                if(nums[l]==0) cnt--;
                l++;  
            } 
             
            r++;
            maxi=max(maxi, r-l);
        }
        return maxi-1;  
    }
};