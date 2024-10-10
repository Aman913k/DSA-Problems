class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size(); 
        
        vector<int> suff(n);
        suff[0]=nums[n-1]; 
        
        for(int i=1; i<n; i++) suff[i]=max(nums[n-i-1], suff[i-1]);
        int ans=INT_MIN; 
         
                   
        for(int i=0; i<n; i++){
            int tar=nums[i];  
            int l=0, h=n-i-2; 
            
            while(l<=h){
                int mid=l+(h-l)/2;   
                if(suff[mid]>=tar) h=mid-1;
                else l=mid+1;
            }
        
            if(h+1>=0 && h+1<n && suff[h+1]>=tar) ans=max(ans, n-h-2-i);
        }
        return ans; 
        
    }
};