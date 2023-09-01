int cnt1(int n){
    int cnt=0;

    while(n>0){
        if(n&1) cnt++;
        n=n>>1;
    }
    
    return cnt;
}


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        
        for(int i=1; i<=n; i++){
            ans[i]=cnt1(i);
        }
        
        return ans;
    }
};