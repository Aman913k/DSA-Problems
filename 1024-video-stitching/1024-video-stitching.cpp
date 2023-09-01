int dp[101][101];  
class Solution {
public:
    int helper(vector<vector<int>>& clips, int time, int indx, int endT){
        if(endT>=time) return 0;
        if(indx>=clips.size()) return 1e9;
        
        if(dp[indx][endT]!=-1) return dp[indx][endT];
    
        int pick=1e9, nonpick=1e9;     
        
        if(clips[indx][0]<=endT) pick=1+helper(clips, time, indx+1, clips[indx][1]);
        nonpick=helper(clips, time, indx+1, endT);
        
        return dp[indx][endT]=min(pick, nonpick);
        
    } 
    

    
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
     
        memset(dp, -1, sizeof dp); 
        int ans=1e9;
        
        for(int i=0; i<clips.size(); i++){
            if(clips[i][0]==0) ans=min(ans, 1+helper(clips, time, i+1, clips[i][1]));
        }
        
        if(ans==1e9) return -1;
        return ans;  
    }
};