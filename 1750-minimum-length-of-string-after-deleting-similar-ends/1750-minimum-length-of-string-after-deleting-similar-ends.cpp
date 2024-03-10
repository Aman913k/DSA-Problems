class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int i=0, j=n-1;
        
        while(i<j){
            while(i+1<n && s[i]==s[i+1] && s[i]==s[j]) i++;
            while(j-1>=0 && s[j]==s[j-1] && s[i]==s[j]) j--;
            
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else break;  
        }
        
        return max(0, j-i+1);   
    }
};