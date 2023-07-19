bool comp(const vector<int>& a, const vector<int>& b){
        return a[1]<b[1];
    }

class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp); 
        int n=intervals.size();  
        int cnt=1;
        
        int prevBeg=intervals[0][0];
        int prevEnd=intervals[0][1];  
        
        for(int i=1; i<n; i++){
            if(intervals[i][0]>=prevEnd){
                cnt++;
                prevBeg=intervals[i][0];
                prevEnd=intervals[i][1];
            }
            
        }
        
        return n-cnt;  
        
        
    }
};