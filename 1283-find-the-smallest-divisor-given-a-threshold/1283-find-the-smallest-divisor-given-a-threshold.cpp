class Solution {
public:
    bool helper(vector<int>& nums, int threshold, int divisor){
        int n=nums.size();
        int total=0;
        
        for(int i=0; i<n; i++){
            total+=ceil(double(nums[i])/double(divisor));
        }
        
        if(total<=threshold) return true;  
        return false;
    }
    
    
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int beg=1, end=1e6;   
        
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            
            if(helper(nums,threshold, mid)) end=mid-1;
            else beg=mid+1;
        }
        
        return beg;   
    }
};