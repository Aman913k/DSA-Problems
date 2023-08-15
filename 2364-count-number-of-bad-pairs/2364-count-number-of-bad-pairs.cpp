class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long cnt=0;
        unordered_map<int,int> mp;
        int n=nums.size(); 
        
        for(int i=0; i<n; i++){
            cnt+=mp[nums[i]-i];
            mp[nums[i]-i]++;
        }
        
        cout<<cnt;
        long long ans=(long long)n*(n-1)/2;
        ans-=cnt;        
        return ans;    
    }
};