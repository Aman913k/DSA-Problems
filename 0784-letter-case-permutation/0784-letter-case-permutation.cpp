class Solution {
public:
    void helper(string &s, int n, int indx, string strng, set<string>& stt){
        if(indx==n){
            stt.insert(strng);     
            return;  
        }           
              
        // pick         
        helper(s, n, indx+1, strng+char(toupper(s[indx])), stt);
        helper(s, n, indx+1, strng+char(tolower(s[indx])), stt);
          
        // nonpick     
        helper(s, n, indx+1, strng+s[indx], stt);
    }  
    
    vector<string> letterCasePermutation(string s) {
        int n=s.size();
        set<string> stt;
        string strng="";           
            
        helper(s, n, 0, strng, stt);   
        vector<string> ans;  
        for(auto i: stt) ans.push_back(i);
        return ans;
        
    }
};