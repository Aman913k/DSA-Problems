class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int l=0,r=0;
        int count=0;
        int ans=1;
        int n=s.size(); 
        while(r<n-1){
            r++;
            if(s[r]==s[r-1]) count++;  
            while(count>=2){
                l++;
                if(s[l]==s[l-1]) count--;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};