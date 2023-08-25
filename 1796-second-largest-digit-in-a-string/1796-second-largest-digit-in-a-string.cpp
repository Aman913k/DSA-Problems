class Solution {
public:
    int secondHighest(string s) {
        int maxi=-1;
        
        for(auto i: s){
            if(isdigit(i)) maxi=max(maxi, i-'0');
        }
        
        int ans=-1;
        for(auto i: s){
            if(isdigit(i) && i-'0'!=maxi) ans=max(ans, i-'0');
        }
        
        return ans;       
    }
};