class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        
        int i=0, j=n-1;
        int curr_score=0, max_score=0; 
        sort(tokens.begin(), tokens.end()); 
        
        while(i<=j){
            if(tokens[i]<=power){
                power-=tokens[i];
                curr_score+=1;
                max_score=max(max_score, curr_score); 
                i++; 
            }
            else if(curr_score>0){
                power+=tokens[j];
                curr_score-=1;
                j--; 
            }
            else break;
        }
        
        return max_score; 
    }
};