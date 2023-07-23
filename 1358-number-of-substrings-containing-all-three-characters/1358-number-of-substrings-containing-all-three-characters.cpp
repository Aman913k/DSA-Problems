class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;  
        int n=s.size();
        int r=0, l=0;
        int ans=0;
        
        while(r<n){
            mp[s[r]]++;
            
            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1){
                ans=ans+(1+(n-1)-r);            
                mp[s[l]]--;
                l++;
            }
            
            r++;
        }
        
        return ans; 
    }
};