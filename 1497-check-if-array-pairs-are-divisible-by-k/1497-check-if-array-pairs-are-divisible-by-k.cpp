class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();  
        vector<int> temp=arr;
        unordered_map<int,int> mp; 
        
        for(int i=0; i<n; i++) temp[i]=(temp[i]%k+k)%k; 
        for(auto i: temp) mp[i]++;
        for(auto i: temp) cout<<i<<" ";
        cout<<endl;
        
        for(auto i: temp){
            if(k-i==k && mp.find(0)!=mp.end()){
                if(mp[0]&1) return false;
            }
            else if(mp.find(k-i)!=mp.end()){
                mp[k-i]--;
                if(mp[k-i]==0) mp.erase(k-i);
            }
            else return false;
        }
        return true;
         
    }
};