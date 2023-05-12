class Solution {
public:
    long long helper(vector<vector<int>>& questions, int indx, vector<long long>& dp){
        int n=questions.size();
        if(indx>=n) return 0;
        if(dp[indx]!=-1) return dp[indx];
         
        long long pick=0;  
        pick+=questions[indx][0]+helper(questions, indx+questions[indx][1]+1, dp);
        long long nonpick=0+helper(questions, indx+1, dp);    
        
        return dp[indx]=max(pick, nonpick);  
    }
    
    
    
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        int m=questions[0].size();
          
        vector<long long> dp(n, -1);
        return helper(questions, 0, dp);
        
          
    }
};