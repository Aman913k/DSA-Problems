class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        unordered_map<int,int> mp2;    
        
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        for(auto i: mp){
            if(!mp2[i.second]) mp2[i.second]=1;
            else return false;
        }
        return true;    
          
    }
};