class Solution {
public:
    int ans=0;
    int numberOfMatches(int n) {
        while(n!=1){
            if(n%2){
                ans+=(n-1)/2;
                n=(n-1)/2+1;
            }
            else{
                ans+=n/2;
                n/=2;
            }
        
        }
        return ans;
    }
};