class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size(); 
        vector<int> Seen(101), ans; 
        for(int i=n-1; i>=0; i--){ 
            int mini=INT_MAX;      
            for(int j=temp[i]+1; j<=100; j++){
                if(Seen[j]) mini=min(mini, Seen[j]-i);
            }
            if(mini!=INT_MAX) ans.push_back(mini);
            else ans.push_back(0);  
            Seen[temp[i]]=i; 
        }
        reverse(ans.begin(), ans.end()); 
        return ans;     
    }
};