class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans(nums.size()); 
        int n=nums.size();
        int k=0;
        int l=n-1;
        for(int i=0; i<n; i++){
            if(nums[i]%2==0){
                ans[k++]=nums[i];
            }
            else ans[l--] =nums[i];
        }
        return ans; 
    }
};