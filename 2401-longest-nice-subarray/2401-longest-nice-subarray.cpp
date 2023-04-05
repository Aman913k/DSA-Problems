class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0,r=0;
        int n=nums.size();
        int num=0, ans=0;    
                   
        while(r<n){        
            while((num & nums[r])!=0){
                num^=nums[l]; 
                l++;
            }
             
            ans=max(ans, r-l+1);  
            num|=nums[r];   
            r++;
        }
        return ans;   
    }
};