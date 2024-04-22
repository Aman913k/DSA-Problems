class Solution {
public:
    void fillNeighbours(queue<string>&q, string& curr, unordered_map<string,int>& vis, set<string>& st){
        vis[curr]++;
        
        for(int i=0; i<4; i++){
            char charr=curr[i];
            char decr= charr=='0'?'9':charr-1;
            char incr= charr=='9'?'0':charr+1;
            
            curr[i]=decr;
            if(vis.find(curr)==vis.end() && st.find(curr)==st.end()){
                vis[curr]++;
                q.push(curr);
            } 
              
            curr[i]=incr;  
            if(vis.find(curr)==vis.end() && st.find(curr)==st.end()){
                vis[curr]++;
                q.push(curr);
            } 
            
            curr[i]=charr;
            
        }
    }
    
    
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        set<string> st;  
        unordered_map<string, int> vis; 
        
        for(auto i: deadends) st.insert(i); 
        
        string start="0000"; 
        int level=0;
        
        if(st.find(start)!=st.end()) return -1; 
        q.push(start);
        
        while(!q.empty()){
            int sz=q.size();
               
            while(sz--){
                string frnt=q.front();
                q.pop();
                if(frnt==target) return level;
                
                fillNeighbours(q, frnt, vis, st);
            }
            
            level++;      
            
        }
        
        return -1; 
    }
};