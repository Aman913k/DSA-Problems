class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefSum=0;
        int n=nums.size();
        unordered_map<int,int>mp; 
        
        for(int i=0; i<n; i++){
            prefSum+=nums[i];   
            int k1=k;  
            
            if(i>0 && mp.find(prefSum)!=mp.end() && nums[i]==0 && nums[i-1]==0) return true; 
            while(k1<=prefSum){  
                if(mp.find(prefSum-k1)!=mp.end() && i-mp[prefSum-k1]>1){
                    return true; 
                }    
                else if(prefSum%k==0 && i>0) return true;  
                k1+=k;
            }
            if(mp.find(prefSum)==mp.end()) mp[prefSum]=i;
            
        }
        return false;   
    }
};