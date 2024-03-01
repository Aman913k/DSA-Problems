class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size(); 
        int cnt1=0;
        for(auto i: s) if(i=='1') cnt1++;
        
        string ans="";
        int x=n;
        
        while(x>0){
            if(cnt1>1){
                ans+='1';
                cnt1--;
            }
            else ans+='0'; 
            x--;
        }
        ans[n-1]='1';
        return ans;
        
    }
};