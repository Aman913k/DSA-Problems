class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multi) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i=0; i<nums.size(); i++) pq.push({nums[i], i});
        
        while(k--){
            auto tp=pq.top();
            pq.pop();
            pq.push({tp.first*multi, tp.second});
        }
        
        vector<int> ans(nums.size());
        while(!pq.empty()){
            ans[pq.top().second]=pq.top().first;
            pq.pop();
        }
        
        return ans; 
    }
};