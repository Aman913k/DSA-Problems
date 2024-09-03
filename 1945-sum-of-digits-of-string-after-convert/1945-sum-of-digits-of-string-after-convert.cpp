class Solution {
public:
    int getLucky(string s, int k) {
        string t; 

        for(int i=0; i<s.size(); i++) t+=to_string(s[i]-'a'+1);
        
        int sum=0;
        int ans=0;
        while(k--){          
            for(int i=0; i<t.size(); i++) sum+=(t[i]-'0');
            t=to_string(sum); 
            ans=sum;
            sum=0;
            
        }
        
        return ans;   
    }
};