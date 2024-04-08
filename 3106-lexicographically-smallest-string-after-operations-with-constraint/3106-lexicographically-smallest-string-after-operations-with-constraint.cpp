class Solution {
public:
    string getSmallestString(string s, int k) {
        int n=s.size();
        int cnt=0;
        
        for(int i=0; i<n; i++){
            while(s[i]!='a'){
                if(k==0) break;
                if(s[i]=='z'){
                    s[i]='a';
                    k--;
                    break;
                }
                if(s[i]<='m') s[i]--;
                else{
                    if(k>=(('z'-s[i])+1)) s[i]++;
                    else s[i]--; 
                }
                k--;
                
            }

            if(k==0) break; 
        }
        
        return s;     
    }
};