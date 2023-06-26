class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        int prefSumEnd=0;
        int prefSum=0;
        if(n==1) return 0;
        
        for(int i=0; i<n; i++) prefSumEnd+=nums[i];
        
        for(int i=0; i<n; i++){
            prefSum+=nums[i];
            if(prefSum-nums[i]==prefSumEnd-prefSum) return i;      
        } 
        
        return -1; 
    }
};