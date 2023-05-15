class Solution {
public:
    void dfs(vector<int> adj[], vector<int>& vis, int node, int& vertex, int& edge){
        vis[node]=1;
        vertex++;
        edge+=adj[node].size();     
        
        for(auto it: adj[node]){  
            if(!vis[it]){
                dfs(adj, vis, it, vertex, edge); 
            }        
        }  
        
    }
    
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n, 0);
        int cnt=0;
        
        for(int i=0; i<n; i++){
            int vert=0, edge=0;
            if(!vis[i]){
                dfs(adj, vis, i, vert, edge);
                if(vert*(vert-1)==edge) cnt++;
            }
        }
        return cnt; 
    }
};  