class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> bann(1e4+1);
        int tot=0; 
        for(auto i: banned) bann[i]++;
        
        int cnt=0;     
        int start=1;
        while(tot+start<=maxSum && start<=n){
            if(bann[start]==0){
                tot+=start;
                cnt++;
            }
            start++;
        }
        return cnt; 
    }
};