class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<int,int> mp;
        int cnt=0;
        
        for(auto i: word) mp[i]++; 
        
        for(int i='A'; i<='Z'; i++){ 
            if(mp.find(i)!=mp.end() && mp.find(i+32)!=mp.end()) cnt++;
        }
        
        return cnt;  
    }
};