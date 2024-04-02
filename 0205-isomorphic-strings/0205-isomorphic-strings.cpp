class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int, int> mp, mp2;
        
        for(int i=0; i<s.size(); i++){
            if(mp[s[i]] && mp[s[i]]!=t[i]) return false;
            else{
                if(mp2[t[i]] && t[i]!=mp[s[i]]) return false;
                else{
                    mp[s[i]]=t[i]; 
                    mp2[t[i]]++;  
                }      
            }
        }
        
        return true;  
    }
};