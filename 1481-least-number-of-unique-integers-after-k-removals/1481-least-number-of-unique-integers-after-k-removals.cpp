class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        
        unordered_map<int,int> mp; 
        for(int i=0; i<n; i++) mp[arr[i]]++;
        
        vector<vector<int>> vp;
        for(auto i: mp){
            vp.push_back({i.second, i.first}); 
        }
        
        sort(vp.begin(), vp.end());
        
        for(int i=0; i<vp.size(); i++){
            if(vp[i][0]==k){
                k-=vp[i][0];
                vp[i][0]=0; 
            }
            else if(vp[i][0]<k){
                k-=vp[i][0]; 
                vp[i][0]=0;
            }
        }
        
        for(auto i: vp) cout<<i[0]<<" "<<i[1]<<"   ";  
        int cnt=0; 
        for(auto i: vp) if(i[0]>0) cnt++;
        return cnt;  
    }
};