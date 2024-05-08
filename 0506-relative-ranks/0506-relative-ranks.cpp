class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n=nums.size();  
        vector<string> ans(n);
         
        priority_queue<pair<int,int>> pq;
        int itr=1;
        
        for(int i=0; i<n; i++) pq.push({nums[i], i}); 
        while(!pq.empty()){
            if(itr==1) ans[pq.top().second]="Gold Medal";
            else if(itr==2) ans[pq.top().second]="Silver Medal";
            else if(itr==3) ans[pq.top().second]="Bronze Medal";
            else ans[pq.top().second]=to_string(itr);  
            itr++; 
            pq.pop();
        }
        
        return ans;
    }
};