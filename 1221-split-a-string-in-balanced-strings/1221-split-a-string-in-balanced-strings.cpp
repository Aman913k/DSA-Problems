class Solution {
public:
    int balancedStringSplit(string s) {
        int cntR=0, cntL=0;
        int n=s.size();
        int cnt=0; 
        
        for(int i=0; i<n; i++){
            if(cntR==cntL && cntR>0){
                cnt++;
                cntR=0;
                cntL=0;
            }
                
            if(s[i]=='R') cntR++;
            else cntL++;
        }
        
        return cnt+1; 
    }
};