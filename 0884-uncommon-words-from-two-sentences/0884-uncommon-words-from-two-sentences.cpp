class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        string word="";   
        
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=' ' && i!=s1.size()-1) word+=s1[i];
            else{
                if(i==s1.size()-1) word+=s1[i];
                mp[word]++;
                word="";
            }                
        }
        
        word="";
        
        for(int i=0; i<s2.size(); i++){  
            if(s2[i]!=' ' && i!=s2.size()-1) word+=s2[i];
            else{
                if(i==s2.size()-1)word+=s2[i];
                mp[word]++;
                word="";
            }
        }     
        
        vector<string> ans;   
        
        for(auto i: mp){
            if(i.second==1) ans.push_back(i.first);
        }
        return ans;
    }
};