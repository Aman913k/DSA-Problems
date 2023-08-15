class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int prefSum=0;
        
        mp[0]=1;
        int cnt=0;  
        for(int i=0; i<nums.size(); i++){
            prefSum+=nums[i];
            
            if(prefSum%k<0) cnt+=mp[(prefSum%k)+k]++;
            else cnt+=mp[prefSum%k];
           
            mp[prefSum%k]++;
        }
        
        return cnt;
    }
};