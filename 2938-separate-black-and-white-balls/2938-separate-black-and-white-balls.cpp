class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        long long ans=0; 
        long long cnt1=0; 
        
        for(int i=n-1; i>=0; i--){
            if(s[i]=='1') ans+=(n-1-i-cnt1), cnt1++; 
        }
        
        return ans; 
    }
};