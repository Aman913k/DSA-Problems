class Solution {
public:
    int bestClosingTime(string s) {
        int n=s.size();
        
        vector<int> pref(n+1, 0);   //  N
        vector<int> suff(n+1, 0);   //  Y
        
        int cntY=0, cntN=0;
        for(int i=0; i<n; i++){
            if(s[i]=='N') pref[i+1]=pref[i]+1;
            else pref[i+1]=pref[i];
        }  
        
        for(int i=n-1; i>=0; i--){
            if(s[i]=='Y') suff[i]=suff[i+1]+1;
            else suff[i]=suff[i+1]; 
        }
        
        int mini=INT_MAX;
        int indx;
        
        for(int i=0; i<=n; i++){
            if(pref[i]+suff[i]<mini){
                mini=pref[i]+suff[i];
                indx=i;
            }
        }
        
        return indx;       
    
    }
};