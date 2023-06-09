class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr=0;
        for(auto num: nums) xorr^=num;
        
        long long lastSbit=xorr&~(xorr-1);
        
        int a=0, b=0;
        
        for(auto num: nums){
            if(num&lastSbit) a^=num;
            else b^=num;
        }
        return {a,b};     
    }
};