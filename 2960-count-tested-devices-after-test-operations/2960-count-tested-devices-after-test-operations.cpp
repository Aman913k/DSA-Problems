class Solution {
public:
    int countTestedDevices(vector<int>& batt) {
        int n=batt.size();
        vector<int> vis(n);
        int cnt=0;
        
        for(int i=0; i<n; i++){
            if(batt[i]==0) continue;
            for(int j=i+1; j<n; j++){
                batt[j]=max(0, batt[j]-1);
            }
            if(batt[i]>0) cnt++;
        }
        
        return cnt;
    }
};