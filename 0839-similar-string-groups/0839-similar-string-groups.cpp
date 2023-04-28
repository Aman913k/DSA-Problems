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
    
    void bfs(int node, vector<int> adj[], vector<int>& vis){
        vis[node]=1;
        queue<int> q;
        q.push(node);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    
    
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size(); 
        vector<int> adj[n];
        vector<int> vis(n, 0); 
         
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(is_similar(strs[i], strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int ans=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                bfs(i, adj, vis);     
                ans++;
            }     
        }
        return ans;    
    }
};