class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string t="";
        
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                reverse(t.begin(), t.end());
                ans+=t;
                ans+=' ';
                t="";
            }
            else t+=s[i];
        }
        reverse(t.begin(), t.end());
        ans+=t;
        
        return ans;
    }
};