class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans="";
        int fg=0;
        for(auto i: s){
            if(i=='1' && fg==0){
                fg=1;
                continue;
            }
            else ans+=i;
        }
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end()); 
        ans+='1';
        return ans;
    }
};