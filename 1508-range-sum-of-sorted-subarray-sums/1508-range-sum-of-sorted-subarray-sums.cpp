int mod=1e9+7; 
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) { 
        vector<int> pref;
        pref.push_back(0);        
        
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum=(sum%mod+nums[j]%mod)%mod;
                pref.push_back(sum); 
            }
        }
        sort(pref.begin(), pref.end());  
        for(int i=1; i<pref.size(); i++) pref[i]=(pref[i]%mod+pref[i-1]%mod)%mod; 
        return pref[right%mod]-pref[left%mod-1]; 
    }
};