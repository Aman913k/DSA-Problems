class Solution {
public:
    string reversePrefix(string word, char ch) {
        int fIndx=-1, n=word.size();
        string t="";
        
        for(int i=0; i<n; i++){
            if(word[i]==ch){
                fIndx=i;
                t+=word[i];
                break;
            }
            else t+=word[i]; 
        }
        
        if(fIndx==-1) return word;
        reverse(t.begin(), t.end());
        for(int i=fIndx+1; i<n; i++){
            t+=word[i];
        }
        return t; 
    }
        
};