class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int mini=neededTime[0];
        char ch=colors[0];
        int ans=0;
        
        for(int i=1; i<colors.size(); i++){
            if(colors[i]==ch){
                ans+=min(mini, neededTime[i]);
                mini=max(mini,  neededTime[i]);
            }
            else{
                mini=neededTime[i];
                ch=colors[i];  
            }
        }
        
        return ans;
    }
};