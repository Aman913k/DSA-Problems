class Solution {
public:
    int numSteps(string s) {
        int n=s.size();
        
        int last=0; 
        int cnt=0;
        for(int i=n-1; i>0; i--){
            if(s[i]-'0'+last==1){
                cnt++;
                last=1;
            }
        }
        
        return n-1+cnt+last;  
    }
};