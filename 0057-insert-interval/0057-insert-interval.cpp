class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intv, vector<int>& newIntv) {
        
        int n=intv.size(); 
        vector<vector<int>> temp, ans;
        temp=intv;
        
        auto it=lower_bound(temp.begin(), temp.end(), newIntv, [](const vector<int>& a, const vector<int>& b){
            return a[0]<b[0];
        });
        
        temp.insert(it, newIntv);

        int startIntv=temp[0][0], endIntv=temp[0][1];
        for(int i=1; i<n+1; i++){
            if(temp[i][0]<=endIntv){
                endIntv=max(endIntv, temp[i][1]); 
            }
            else{
                ans.push_back({startIntv, endIntv});
                startIntv=temp[i][0];
                endIntv=temp[i][1]; 
            }  
        }
          
        ans.push_back({startIntv, endIntv});
        return ans;                     
    }
};