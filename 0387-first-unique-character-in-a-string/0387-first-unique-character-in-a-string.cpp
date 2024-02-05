class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> seen(26);
        
        for(int i=0; i<s.size(); i++){
            if(seen[s[i]-'a']) seen[s[i]-'a']=-1;
            else seen[s[i]-'a']=i+1; 
        }
        
        for(int i=0; i<s.size(); i++){
            if(seen[s[i]-'a']!=-1) return seen[s[i]-'a']-1;
        }
        
        return -1;   
    }
};