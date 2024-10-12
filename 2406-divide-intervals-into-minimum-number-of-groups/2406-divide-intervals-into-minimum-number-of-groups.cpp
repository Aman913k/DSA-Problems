class Solution {
public:
    int minGroups(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        int cnt=0;
        priority_queue<int, vector<int>, greater<int>> pq; 
        
        for(int i=0; i<nums.size(); i++){
            if(!pq.empty() && nums[i][0]>pq.top()){
                pq.pop(); 
            } 
            pq.push(nums[i][1]);
        }
        
        return pq.size(); 
    }
};