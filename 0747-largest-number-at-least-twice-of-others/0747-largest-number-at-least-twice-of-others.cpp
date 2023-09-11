class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi=*max_element(nums.begin(), nums.end());
        
        int num=INT_MIN;
        int indx=-1;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=maxi && nums[i]>num) num=nums[i];
            if(nums[i]==maxi) indx=i; 
        }
        
        if(maxi>=2*num) return indx;
        return -1;
         
    }
};