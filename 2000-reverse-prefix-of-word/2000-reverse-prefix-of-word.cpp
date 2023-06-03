class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n=word.size();
        string s="";
        int i=0;
        
        for(i=0; i<n; i++){
            if(word[i]==ch){
                s+=word[i];
                break;     
            }
            else s+=word[i];
        }
        string ans="";
        reverse(s.begin(), s.end());
        ans=s;
        cout<<ans;  
        for(int k=i+1; k<n; k++){
            ans+=word[k];
        }
        
        if(i==n) return word;     
        return ans;  
    }
};