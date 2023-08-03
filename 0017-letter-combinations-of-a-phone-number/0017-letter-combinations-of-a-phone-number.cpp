vector<string> mp={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


void helper(string digits, vector<string>& ans, int indx, int n, string& s){
      
    if(s.size()==n){
        ans.push_back(s);
        return; 
    }
    if(indx>=n) return;
    
    
    int idx=digits[indx]-'0';
    
    for(int i=0; i<mp[idx].size(); i++){
        s+=mp[idx][i];    
        helper(digits, ans, indx+1, n, s);
        s.pop_back(); 
    }
    
}



  


class Solution {
public:     
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n=digits.size();
        if(n==0) return {};
        string s="";
        
        helper(digits, ans, 0, n, s);
        return ans;
    }
};