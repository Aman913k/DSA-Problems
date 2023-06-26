class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();  
        vector<int> prefSum(n,0);
        prefSum[0]=nums[0];
        
        for(int i=1; i<n; i++) prefSum[i]=prefSum[i-1]+nums[i];
        
        if(prefSum[0]==prefSum[n-1]) return 0;
        
        for(int i=1; i<n; i++) if(prefSum[i-1]==prefSum[n-1]-prefSum[i]) return i; 
        
        return -1; 
    }
};