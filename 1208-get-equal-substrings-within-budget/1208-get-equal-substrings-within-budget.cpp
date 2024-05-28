class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int l=0, r=0;
        
        int cost=0;
        int ans=0;
        while(r<n){
            cost+=abs(s[r]-t[r]); 
            
            if(cost>maxCost){
                cost-=abs(s[l]-t[l]); 
                l++; 
            }
             
            ans=max(ans, r-l+1); 
            r++;
            
        }
        
        return ans;
    }
};