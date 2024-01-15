class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> mp1, mp2;
        vector<int> v1, v2;
        
        for(auto i: matches){
            mp1[i[0]]++;
            mp2[i[1]]--; 
        }
          
        for(auto i: mp1){
            if(i.second>=1 && mp2[i.first]==0) v1.push_back(i.first); 
        }      
        
        for(auto i: mp2){
            if(i.second==-1) v2.push_back(i.first);  
        }
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());   
        return {v1, v2};   
    }
};