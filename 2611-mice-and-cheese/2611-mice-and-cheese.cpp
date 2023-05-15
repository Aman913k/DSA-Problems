class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n=reward1.size(); 
        
        priority_queue<pair<int,int>> pq;
        int ans=0;
        
        for(int i=0; i<n; i++){
            pq.push({reward1[i]-reward2[i], i});
            ans+=reward2[i];
        }
         
        for(int i=0; i<k; i++){
            ans+=reward1[pq.top().second];
            ans-=reward2[pq.top().second];
            pq.pop();
        }         
    
        return ans;            
    }
};