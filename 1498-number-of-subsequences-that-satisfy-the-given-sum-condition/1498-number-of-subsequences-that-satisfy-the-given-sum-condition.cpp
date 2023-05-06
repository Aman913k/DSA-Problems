class Solution {
public:
    const int mod=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> exps(n, 1);
        for(int i=1; i<n; i++) exps[i]=(2*exps[i-1])%mod; 
        
        int l=0, r=n-1;
        int cnt=0;    
        
        while(l<=r){
            if(nums[l]+nums[r]>target) r--;
            else{
                cnt=cnt%mod+(exps[r-l]%mod);   
                l++;
            }    
        }
        return cnt;  
    }
};