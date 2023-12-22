class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int cnt0=0, ans=0;
        
        for(int i=0; i<n-1; i++){
            int cnt1=0;
            if(s[i]=='0') cnt0++;
            for(int j=i+1; j<n; j++){
                if(s[j]=='1') cnt1++;
            }
            ans=max(ans, cnt0+cnt1);
        }
        return ans;
    }
};