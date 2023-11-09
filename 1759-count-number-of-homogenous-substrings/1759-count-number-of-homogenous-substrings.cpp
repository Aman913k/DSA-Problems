int mod=1e9+7;
class Solution {
public:
    int countHomogenous(string s) {
        string t;
        t=s[0];
        int ans=0; 
        //ans+=t.size(); 
        
        for(int i=1; i<s.size(); i++){
            ans=ans%mod+t.size()%mod;
              
            if(s[i]==s[i-1]) t+=s[i];
            else t=s[i];     
        }
        
        ans=ans%mod+t.size()%mod;  
        return ans%mod; 
    }
};