class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intv, vector<int>& newIntv) {
        
        int n=intv.size(); 
        vector<vector<int>> temp, ans;  
        
        for(int i=0; i<n; i++){
            temp.push_back({intv[i][0], intv[i][1]});     
        }
        temp.push_back({newIntv[0], newIntv[1]});
        sort(temp.begin(), temp.end());
        
        
        int startIntv=temp[0][0], endIntv=temp[0][1];
        for(int i=1; i<n+1; i++){
            if(temp[i][0]<=endIntv){
                endIntv=max(endIntv, temp[i][1]); 
            }
            else{
                ans.push_back({startIntv, endIntv});
                startIntv=temp[i][0];
                endIntv=temp[i][1]; 
            }  
        }
          
        ans.push_back({startIntv, endIntv});
        return ans;                     
    }
};