class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int prefSum=0;
        int cnt=0;   
        unordered_map<int,int> mp;
        mp[0]=1; 
        
        for(int i=0; i<n; i++){
            prefSum+=nums[i];
            
            int remove=prefSum-goal;
            cnt+=mp[remove];
            mp[prefSum]++;
        }
        
        return cnt;
    }
};