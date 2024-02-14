class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size(); 
        vector<int> ans(n);
        int k1=0, k2=1;
        
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                ans[k1]=nums[i];
                k1+=2;
            }
            else{
                ans[k2]=nums[i]; 
                k2+=2; 
            }
        }
        
        return ans;  
        
    }
};