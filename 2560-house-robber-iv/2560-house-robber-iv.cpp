class Solution {
public:
    bool check(vector<int>& nums, int k, int mid){
        int i=0, n=nums.size();
        
        while(i<n){
            if(nums[i]<=mid){
                i+=2;      
                k--;
                if(k==0) return true; 
            }
            else i++;
        }
        return (k==0);
    }
    
    
    
    int ans=INT_MAX;    
    int minCapability(vector<int>& nums, int k) {
        int beg=1, end=1e9+1;
        
        while(beg<end){
            int mid=(beg+end)/2;
            
            if(check(nums, k, mid)){
                end=mid;
                ans=min(ans,mid);
            }
            else beg=mid+1;
        }
        return ans;      
        
    }
};