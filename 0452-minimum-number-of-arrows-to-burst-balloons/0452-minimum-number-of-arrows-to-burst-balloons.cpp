class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        int cnt=1;  
        sort(points.begin(), points.end());
        
        int start=points[0][0];
        int end=points[0][1];
        
        for(int i=1; i<n; i++){  
            if(points[i][0]>=start && points[i][0]<=end){
                start=points[i][0];
                end=min(end, points[i][1]);
            }
            else{
                cnt++;
                start=points[i][0];
                end=points[i][1];  
            }
        }
        
        return cnt; 
    }
};