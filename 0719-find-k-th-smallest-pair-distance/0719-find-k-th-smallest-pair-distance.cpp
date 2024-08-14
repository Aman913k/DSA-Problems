class Solution {
public:
    bool check(vector<int>& nums, int k, int mid){
        int tot=0;
        int l=0, r=0; 
        while(r<nums.size()){
            while(nums[r]-nums[l]>mid){l++;}
            tot+=(r-l);
            r++;
        }
        return tot>=k;   
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size(); 
        sort(nums.begin(), nums.end());
         
        int l=0, h=nums[n-1]-nums[0];
        
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(nums, k, mid)) h=mid-1;
            else l=mid+1; 
        }
        
        return l;
    
    }
};