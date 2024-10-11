class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        
        int target=times[targetFriend][0]; 
        sort(times.begin(), times.end());
        set<int> s;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;    // {Departure Time, indx}
        int chair=0, ctr=0;   
        
        for(int i=0; i<n; i++){  
            while(!pq.empty() && pq.top().first<=times[i][0])  s.insert(pq.top().second), pq.pop(); 
            if(!s.empty()){
                chair=*(s.begin());
                s.erase(s.begin());
            } 
            else{
                chair=ctr;
                ctr++;  
            }
             
            pq.push({times[i][1], chair});
            if(times[i][0]==target) return chair;
           
        }
        
        return 0; 
        
    }
};