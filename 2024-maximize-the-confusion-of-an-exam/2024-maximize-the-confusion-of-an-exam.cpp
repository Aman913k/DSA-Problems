class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size(), cntT=0, cntF=0;
        int l=0, r=0, maxi=INT_MIN;
        
        while(r<n){
            if(answerKey[r]=='T') cntT++;
            else cntF++;
            
            while(cntT>k && cntF>k){
                if(answerKey[l]=='T') cntT--;
                else cntF--;
                l++;
            }
            
            maxi=max(maxi, r-l+1);
            r++;
        }
        
        return maxi;  
    }
};