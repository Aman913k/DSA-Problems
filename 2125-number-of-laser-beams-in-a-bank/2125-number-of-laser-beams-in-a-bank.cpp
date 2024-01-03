class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cntPrev=0, cntCurr=0;
        int tot=0;
        
        for(int i=0; i<bank.size(); i++){  
            for(int j=0; j<bank[i].size(); j++){
                if(bank[i][j]=='1') cntCurr++;   
            }
            
            if(cntPrev!=0 && cntCurr!=0){
                tot+=(cntCurr*cntPrev);
            }
            else if(cntCurr==0) continue; 
            cntPrev=cntCurr;
            cntCurr=0;
              
        }
        
        return tot;
        
    }
};