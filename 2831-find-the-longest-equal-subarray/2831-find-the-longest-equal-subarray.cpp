class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        int l=0, r=0;     
        int t=k;
        
        int ans=0;
        unordered_map<int,int> mp;
        int maxFreq=INT_MIN;
        
        while(r<n){
            mp[nums[r]]++;
            maxFreq=max(maxFreq, mp[nums[r]]); 
            
            while(r-l+1-maxFreq>k){
                mp[nums[l]]--;
                l++;
                
            }
            
            
            
            r++;
            ans=max(ans, maxFreq);
            
            
        }  
        
        return ans;   
    
    }
};