class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // WE CAN APPLY TOPO SORT HERE IF THERE IS A CYCLE TOPO SORT FAILS AND WE RETURN FALSE;
        // ELSE RETURN TRUE; 
            
         
        // CREATING ADJENCENCY LIST
        vector<int> adj[numCourses];
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }      
        
        // CREATING INDEGREE OF ALL NODES
        vector<int> in_deg(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            for(auto it: adj[i]){
                in_deg[it]++;  
            }
        }
        
        // INITIALLY, IF NODE(S) HAVE INDEGREE 0 WE WILL PUSH INTO THE QUEUE
        queue<int> q;
        for(int i=0; i<numCourses; i++) if(in_deg[i]==0) q.push(i);
        
        int cnt=0;   
        while(!q.empty()){  
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it: adj[node]){
                in_deg[it]--;
                if(in_deg[it]==0) q.push(it);
            }
        }
        
        if(cnt==numCourses) return true;
        return false;        
        
    }
};