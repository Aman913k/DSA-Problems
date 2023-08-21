class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans(intervals.size()); 
        unordered_map<int,int> mp;
        for(int i=0; i<intervals.size(); i++) mp[intervals[i][0]]=i;
        sort(intervals.begin(), intervals.end());  
          
        vector<int> start;     
        for(auto it : intervals) start.push_back(it[0]);
        
        for(int i=0; i<intervals.size(); i++){  
            auto it=lower_bound(start.begin(), start.end(), intervals[i][1])-start.begin();
            
            //cout<<it<<" "; 
            if(it<intervals.size()){
                ans[mp[intervals[i][0]]]=mp[intervals[it][0]]; 
            }
            else ans[mp[intervals[i][0]]]=-1;              
        }
        
        return ans;  
    }
};