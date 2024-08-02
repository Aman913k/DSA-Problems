class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int l=0, r=0; 
        int cnt1=0;
        
        for(auto i: nums) if(i==1) cnt1++; 
        int mini=INT_MAX;
        int cnt0=0;
        
        vector<int> temp=nums;
        for(auto i: nums) temp.push_back(i);
        
        for(r=0; r<cnt1; r++) if(temp[r]==0) cnt0++;
        mini=min(mini, cnt0); 
        
        for(int i=r; i<2*n; i++){
            if(temp[i]==0) cnt0++;
            if(temp[l]==0) cnt0--;
            l++; 
            mini=min(mini, cnt0); 
        }
        return mini; 
    }
};