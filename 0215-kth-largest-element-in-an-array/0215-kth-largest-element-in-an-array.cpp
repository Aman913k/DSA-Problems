class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for(auto i: nums) pq.push(i);
        
        int ans=0;
        while(k--){
            ans=pq.top();
            pq.pop();
        }
        
        return ans;
    }
};