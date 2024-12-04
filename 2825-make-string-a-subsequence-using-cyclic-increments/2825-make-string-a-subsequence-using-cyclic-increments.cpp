class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n=s.size(), m=t.size();
         
        int i=0, j=0;
        while(i<n&&j<n){  
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else if((s[i]-'a'+1)%26==(t[j]-'a')%26){
                i++;
                j++;
            }
            else i++;
        }
        
        return j>=m; 
    } 
};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     