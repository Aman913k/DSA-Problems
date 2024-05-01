class Solution {
public:
    string reversePrefix(string word, char ch) {
        int fIndx=-1, n=word.size();
        for(int i=0; i<n; i++){
            if(word[i]==ch){
                fIndx=i;
                break;
            }
        }
        
        if(fIndx==-1) return word;
        string t="";
        for(int i=0; i<=fIndx; i++){
            t+=word[i];
        }
        reverse(t.begin(), t.end());
        for(int i=fIndx+1; i<n; i++){
            t+=word[i];
        }
        return t; 
    }
        
};