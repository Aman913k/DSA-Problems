class Solution {
public:  
    int findChampion(int n, vector<vector<int>>& edges) {
        int sz=edges.size(); 
                                                          
        vector<int> adj(n, 0);
        vector<int> vis(n, 0);  
        
         for(int i=0; i<sz; i++){
             adj[edges[i][0]]++;
             adj[edges[i][1]]--;
             
             vis[edges[i][1]]=-1;  
         }       
        
        int maxi=0;
        int ans=0;
        int cnt=0;
        
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                ans=i;
                cnt++; 
            }
        }
        
        if(cnt>1) return -1;
        return ans;
        
        
    }
};  