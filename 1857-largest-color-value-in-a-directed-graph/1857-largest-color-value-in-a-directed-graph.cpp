class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size(); 
        vector<int> adj[n];
        vector<int> indeg(n, 0);
        
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            indeg[edges[i][1]]++;
        }

        queue<int> topo;    
        for(int i=0; i<n; i++) if(indeg[i]==0) topo.push(i);
        
        vector<vector<int>> counts(n, vector<int>(26, 0));
        for (int i=0; i<n; i++) counts[i][colors[i]-'a']++;
        
        int max_count=0;
        int visited=0;
        
        while(!topo.empty()){
            int node=topo.front();
            topo.pop();
            visited++; 
            
            for(auto it : adj[node]) {
                for(int i=0; i<26; i++) {
                    counts[it][i]=max(counts[it][i], counts[node][i] + (colors[it]-'a' == i ? 1 : 0));
                }
                indeg[it]--;
                if(indeg[it]==0) topo.push(it);  
                
            }
            max_count = max(max_count, *max_element(counts[node].begin(), counts[node].end()));
        }
        return visited==n ? max_count: -1;  
    }
};