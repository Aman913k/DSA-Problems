bool comp(const vector<int>& a, const vector<int>& b){
    if(a[0]==b[0]) return a[1]>b[1];
    return a[0]<b[0];
}

class Solution {        
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n=env.size();      
        vector<int> lis;
          
        sort(env.begin(), env.end(), comp);
        int len=0;
        
        for(int i=0; i<n; i++){
            int indx=lower_bound(lis.begin(), lis.end(), env[i][1])-lis.begin();
            if(indx<lis.size()){
                lis[indx]=env[i][1];
            }
            else{
                lis.push_back(env[i][1]);
                len++; 
            }
        }
        
        return len;

    }
};