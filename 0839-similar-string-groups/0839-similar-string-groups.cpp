class Solution {
public:
    
    bool is_similar(string& s1, string& s2){
        int cnt=0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]) cnt++;
        }
        if(cnt==0 || cnt==2) return true;
        return false; 
    }
    
    void dfs(int node, vector<int>& vis, vector<int> adj[]){
        vis[node]=1;
            
        for(auto it: adj[node]){
            if(!vis[it]) dfs(it, vis, adj); 
        }
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        
        vector<int> adj[n];
        
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(is_similar(strs[i], strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(n, 0);     
        int ans=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, adj);
                ans++;
            }
        }
        return ans;
    }
};