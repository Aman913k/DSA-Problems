class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int cnt=0;
        for(auto i: nums) cnt+=mp[i]++;
        
        return cnt;   
    }
};