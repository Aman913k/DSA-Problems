class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> mp;
        int l=0, r=0, n=s.size();
        int maxf=0, ans=0; 
        vector<int> count(26, 0);    
        
        while(r<n){
            count[s[r]-'A']++;  
            maxf=max(maxf, count[s[r]-'A']);
            
            while((r-l+1)-maxf>k){        
                // ans=max(ans, r-l+1);  
                count[s[l]-'A']--;   
                l++;
            }
            ans=max(ans, r-l+1);
            r++;     
        }
        return ans;
    }
};