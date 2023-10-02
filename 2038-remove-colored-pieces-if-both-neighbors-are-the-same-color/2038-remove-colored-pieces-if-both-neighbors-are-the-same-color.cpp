class Solution {
public:
    bool winnerOfGame(string col) {
        int n=col.size();
        int Alice=0, Bob=0; 
        
        for(int i=2; i<n; i++){
            if(col[i]=='B' && col[i-1]=='B' && col[i-2]=='B') Bob++;
            else if(col[i]=='A' && col[i-1]=='A' && col[i-2]=='A') Alice++;
        }
        
        return Alice>Bob; 
    }
};