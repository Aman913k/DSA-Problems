class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gS) {
        int n=gS.size();
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> ans; 
        
        for(int i=0; i<n; i++) mp[gS[i]].push_back(i); 
        
         
        for(auto i: mp){              
            vector<int> temp=i.second;
            vector<int> v; 
            
            for(int j=0; j<temp.size(); j++){
                v.push_back(temp[j]);
                
                if(v.size()==i.first){
                    ans.push_back(v);  
                    v.clear();  
                }
            }
        }
        
        return ans;   
    }
};