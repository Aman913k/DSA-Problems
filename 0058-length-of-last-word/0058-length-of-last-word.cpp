class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size()-1;
        int cnt=0, fg=0; 
        
        for(int i=n; i>=0; i--){
            if(s[i]!=' '){
                cnt++;
                fg=1;
            }
            else if(fg==1) break;
            else continue;
            
            
        }
        return cnt;
    }
};