class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        int cntT=0, cntF=0;
        int l=0, r=0;
        int maxi=INT_MIN;
        
        while(r<n){
            if(answerKey[r]=='T') cntT++;
            else cntF++;
            
            while(cntT>k && cntF>k){
                maxi=max(maxi, r-l);
                if(answerKey[l]=='T') cntT--;
                else cntF--;
                l++;
            }
            maxi=max(maxi, r-l+1);
            r++;
        }
        
        if(maxi==INT_MIN) return n; 
        return maxi;  
    }
};