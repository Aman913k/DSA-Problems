class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int l=0, r=0;
        int maxi=0;   
        
        while(r<n){
            if(nums[r]-nums[l]>2*k) l++;
            
            else maxi=max(maxi, r-l+1);
            r++;
        }
        return maxi;    
    }
};