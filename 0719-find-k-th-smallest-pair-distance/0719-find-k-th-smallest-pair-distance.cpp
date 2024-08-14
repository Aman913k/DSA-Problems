class Solution {
public:
    bool check(vector<int>& nums, int k, int mid){
        int tot=0;
        for(int i=0; i<nums.size()-1; i++){
            int l=i, r=0; 
            while(r<nums.size() && nums[r]-nums[l]<=mid) r++;
            tot+=(r-l-1);
            if(tot>=k) return true;
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