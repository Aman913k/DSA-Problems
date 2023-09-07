class Solution {                                                                         
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod=1;
        int cnt=0;
        
        if(k==0 || k==1) return 0;   
        
        int l=0, r=0;
        
        while(r<nums.size()){                
            prod*=nums[r];
             
            while(prod>=k){
                prod/=nums[l];
                l++;  
            }
              
            cnt+=r-l+1;
            r++; 
        }
        
        return cnt;
        
    }
};