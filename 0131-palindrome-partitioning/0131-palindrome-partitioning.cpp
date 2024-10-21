bool isPalin(string& t){
    int l=0, r=t.size()-1;
    while(l<r){
        if(t[l]!=t[r]) return false;
        l++;
        r--; 
    }
    return true; 
}


void dfs(string &s, vector<vector<string>>&ans, vector<string>& v,  int indx){
    
    if(indx>=s.size()){  
        ans.push_back(v); 
        return; 
    }
    string t; 
    for(int i=indx; i<s.size(); i++){  
        t+=s[i];     
        if(isPalin(t)){
            v.push_back(t);
            dfs(s, ans, v, i+1); 
            v.pop_back();
        } 
    }
}  



class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        dfs(s, ans, v, 0);
        return ans;   
    }
};