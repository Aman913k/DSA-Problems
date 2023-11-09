class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        int ans=1;
        vector<int> tm(n); 
        for(int i=0; i<n; i++){
            tm[i]=ceil((1.0*dist[i])/speed[i]); 
        }
        sort(tm.begin(), tm.end()); 
        
        for(int i=0; i<n; i++){    
            if(tm[i]<i+1) return i;
        }
        
        return n; 
    }
};