class Solution {
public:
    // USING TOPO SORT(BFS)
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adjRev[n];
        vector<int> indeg(n,0); 
        
        for(int i=0; i<n; i++){
            for(auto it: graph[i]){
                adjRev[it].push_back(i);    // REVERSING ALL EDGES OF GRAPH AS THE NODE WITH 
                indeg[i]++;                 // outdegree 0 is considered to be a TERMINAL NODE
            }                               // but the topological sort algorithm DEALS WITH THE
        }                                   // indegrees of the nodes.
        
        queue<int> q;
        for(int i=0; i<n; i++){  
            if(indeg[i]==0) q.push(i);  
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();  
            q.pop();
            topo.push_back(node);
              
            for(auto it: adjRev[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);  
            }  
        }
        sort(topo.begin(), topo.end());  
        return topo; 
    }
};