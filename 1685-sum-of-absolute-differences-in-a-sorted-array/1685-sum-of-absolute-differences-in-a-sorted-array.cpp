class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n+1, 0);
         
        for(int i=1; i<=n; i++) pref[i]=pref[i-1]+nums[i-1];
        
        vector<int> ans(n); 
        for(int i=1; i<=n; i++){
            int leftSum=abs(pref[i-1]-(nums[i-1]*(i-1)));
            int rightSum=abs(abs((pref[n]-pref[i])-(nums[i-1]*(n-i))));
            ans[i-1]=leftSum+rightSum; 
        }
        
        return ans; 
    }
};