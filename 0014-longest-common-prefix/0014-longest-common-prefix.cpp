class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s=strs[0];
        string ss="";
        
        for(int i=1; i<strs.size(); i++){
            for(int j=0; j<strs[i].size(); j++){
                if(s[j]==strs[i][j]) ss+=s[j];
                else break;
            }
            s=ss;
            ss="";
        }
        return s; 
    }
};