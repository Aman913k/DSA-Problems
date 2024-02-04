#define ll long long
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<ll,ll> mp, sumF;
        vector<ll> prefSum(n+1);  
        ll sum=0, maxi=-1e18;
        
       
        for(int i=1; i<=n; i++) prefSum[i]=prefSum[i-1]+nums[i-1]; 
    
        for(int i=0; i<n; i++){      
            if(mp.find(nums[i]-k)!=mp.end()) maxi=max(maxi, prefSum[i+1]-prefSum[mp[nums[i]-k]-1]); 
            if(mp.find(nums[i]+k)!=mp.end()) maxi=max(maxi, prefSum[i+1]-prefSum[mp[nums[i]+k]-1]); 
            
            if(mp.find(nums[i])==mp.end() || prefSum[i+1]<prefSum[mp[nums[i]]]) mp[nums[i]]=i+1; 
        }
        
        if(maxi==-1e18) return 0;   
        return maxi; 
    }
};