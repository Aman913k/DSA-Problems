class Solution {
public:
    char findTheDifference(string s, string t) {
        int c=0;; 
        for(int i=0; i<s.size(); i++){
            c=c^s[i];
            c=c^t[i];
            
        }
        c=c^t[t.size()-1];   
        return c;
    }
};