bool psbl(vector<int>& nums, int bouquetNeed, int flowerNeed, int day){
    int m1=0;
    int k1=0;
    
    for(int i=0; i<nums.size(); i++){

        if(nums[i]<=day){
            k1++;
            
            if(k1==flowerNeed){
                m1++;
                k1=0; 
            }
            
        }
        
        else k1=0;
        
        
    }
    
    return m1>=bouquetNeed; 
}




class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        int n=nums.size();
        if(n<(long)m*k) return -1;
        
        int l=*min_element(nums.begin(), nums.end());
        int h=*max_element(nums.begin(), nums.end());
        
        while(l<=h){
            int mid=l+(h-l)/2;
            if(psbl(nums, m, k, mid)) h=mid-1;
            else l=mid+1;
        }
        
        return l;   
    }
};