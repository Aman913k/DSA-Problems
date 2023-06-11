class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int l=0,r=1;
        int cntPair=0;
        int ans=1;
        
        int n=s.size(); 
        while(r<n){
            if(s[r]==s[r-1]) cntPair++;
            
            while(cntPair>=2){
                if(s[l]==s[l+1]) cntPair--;
                l++;  
            }
            
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};