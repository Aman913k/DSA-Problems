class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int prefSum=0;
        
        mp[0]=1;
        int cnt=0;  
        for(int i=0; i<nums.size(); i++){
            prefSum+=nums[i];
            
            int remainder=prefSum%k;
            if(remainder<0) remainder+=k;
            
            cnt+=mp[remainder]; 
           
            mp[remainder]++;
        }
        
        return cnt;
    }
};