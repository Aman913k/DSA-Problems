class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qr, qd;
        int n=senate.size();         
        
        for(int i=0; i<n; i++){
            if(senate[i]=='R') qr.push(i);
            else qd.push(i); 
        }
        
        while(!qr.empty() && !qd.empty()){
            int qr_frnt=qr.front();   
            int qd_frnt=qd.front();
            qr.pop();
            qd.pop(); 
              
            if(qr_frnt<qd_frnt) qr.push(qr_frnt+n);
            else qd.push(qd_frnt+n);
        }
        return(qr.size()>qd.size())?"Radiant":"Dire";
        
    }     
};