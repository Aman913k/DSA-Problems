class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        //vector<int> adj[n];
        map<int, set<int>> adj; 
        
        int sz=roads.size();
        
        for(int i=0; i<sz; i++){  
            adj[roads[i][0]].insert(roads[i][1]);
            adj[roads[i][1]].insert(roads[i][0]); 
            
        }
        
        int maxi_rank=INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int rank=adj[i].size()+adj[j].size();
                
                if(adj[j].find(i)!=adj[j].end()) rank-=1;
                maxi_rank=max(maxi_rank, rank);
                
            } 
        }
        
        return maxi_rank;          
    }
};