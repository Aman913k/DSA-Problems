class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorr=0, cnt=0;
        for(auto i: nums) xorr^=i;
    
        for(int j=31; j>=0; j--){
            if((xorr&(1<<j))!=(k&(1<<j))) cnt++;
        }
        return cnt;
    }
};