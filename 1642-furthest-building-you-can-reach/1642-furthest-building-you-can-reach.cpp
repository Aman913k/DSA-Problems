class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue<int, vector<int>, greater<int>> pq; 
        int step=0;
        
        for(step=1; step<n; step++){
            if(heights[step]-heights[step-1]>0) pq.push(heights[step]-heights[step-1]);
            if(pq.size()>ladders){
                if(pq.top()>bricks) break;
                else{
                    bricks-=pq.top();
                    pq.pop();
                }
            }
        }
        
        return step-1; 
    }
};