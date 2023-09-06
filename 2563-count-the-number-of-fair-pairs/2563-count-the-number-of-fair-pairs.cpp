class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long cnt=0;  
        
        for(int i=0; i<nums.size(); i++){
            auto indx1=lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i])-nums.begin();
            auto indx2=upper_bound(nums.begin()+i+1, nums.end(), upper-nums[i])-nums.begin();
            
         
            cnt+=indx2-indx1;
        }
        
        return cnt;
    }
};