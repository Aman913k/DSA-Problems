#define ll long long
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n=s.size();
        ll len=0;
        int i;
        
        for(i=0; len<k; i++){
            if(s[i]-'0'>=2 && s[i]-'0'<=9) len*=s[i]-'0';
            else len+=1;
        }
     
        i--; 
        for(; i>=0; i--){
            if(s[i]-'0'>=2 && s[i]-'0'<=9){
                len/=s[i]-'0';
                k%=len;
            }
            
            else if(k==0 || k==len) return string("")+s[i];
            else len--;
        
        }
        return "";
    }
};