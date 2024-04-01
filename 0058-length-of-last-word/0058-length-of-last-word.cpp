class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int cnt=0; 
        int i=n-1;
        
        while(i>=0){
            if(s[i]==' ') i--;
            else break; 
        }
        
        for(int k=i; k>=0; k--){
            if(s[k]!=' ') cnt++;
            else break;
        }
        
        return cnt;
    }
};