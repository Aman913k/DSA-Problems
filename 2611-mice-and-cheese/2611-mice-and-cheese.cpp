class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n=reward1.size(); 
        
        priority_queue<pair<int,int>> pq;
        
        for(int i=0; i<n; i++){
            pq.push({reward1[i]-reward2[i], i});  
        }
        
        vector<int> indx;
        
        int ans=0;  
        for(int i=0; i<k; i++){
            indx.push_back(pq.top().second);   
            pq.pop();
        }
               
        for(auto i: reward2) ans+=i;
        for(int i=0; i<indx.size(); i++){
            ans-=reward2[indx[i]];
            ans+=reward1[indx[i]];
        }
        return ans;            
    }
};