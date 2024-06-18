class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i=0; i<profit.size(); i++){
            pq.push({difficulty[i], profit[i]});
        }
        int maxi=0, maxProfit=0; 
        sort(worker.begin(), worker.end()); 
        
        for(int i=0; i<worker.size(); i++){
            while(!pq.empty() && pq.top().first<=worker[i]){
                maxi=max(maxi, pq.top().second); 
                pq.pop();  
            }
            maxProfit+=maxi;
        }
        
        return maxProfit;  
    }
};