
class Solution {
public:
    int ans=0;
    void dfs(string& s, set<string>& st, int indx){

    
        if(indx>=s.size()){
            int sz=st.size(); 
            ans=max(ans, sz);
            return; 
        }
        string t;
        

        for(int i=indx; i<s.size(); i++){
            t+=s[i]; 
            
            if(st.find(t)==st.end()){
                st.insert(t);
                dfs(s, st, i+1); 
                st.erase(st.find(t));  
            }
        }
        
    }
    
    
    int maxUniqueSplit(string s) {
        int n=s.size();
        string t;
        set<string> st; 
        
        dfs(s, st, 0);
        return ans; 
    }
};   