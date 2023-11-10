class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjPairs) {
        unordered_map<int, vector<int>> mp;
        int n=adjPairs.size();   
        for(auto i: adjPairs){
            mp[i[0]].push_back(i[1]);    
            mp[i[1]].push_back(i[0]);
        }
        
        vector<int> ans(n+1);
        int x;
        for(auto i: mp){
            if(i.second.size()==1){
                x=i.first;
                break;
            }
        }
        
        ans[0]=x;
        unordered_map<int,int> vis;
        vis[x]=1;   
        
        for(int i=1; i<=n; i++){
            if(!vis[mp[x][0]]){
                ans[i]=mp[x][0];
                vis[mp[x][0]]=1;
                x=mp[x][0]; 
            }
            else if(mp[x].size()==1) continue;  
            else{
                ans[i]=mp[x][1];  
                vis[mp[x][1]]=1;
                x=mp[x][1];  
            }
        }
        
        return ans;  
        
    }
};