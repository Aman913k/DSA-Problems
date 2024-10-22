class Solution {
public:
    void dfs(string &s, int indx, vector<vector<string>>& vs, vector<string>& v){
        int n=s.size();
          
        if(indx>=s.size()){ 
            vs.push_back(v); 
            return;   
        }
         
        string t;   
        for(int i=indx; i<s.size(); i++){
            t+=s[i];  
            v.push_back(t);
            dfs(s, i+1, vs, v);  
            v.pop_back(); 
        }  
        
    }
    
      
    
    int punishmentNumber(int n) {
        int ans=0;
        
        for(int i=1; i<=n; i++){   
            string s=to_string(i*i); 
            
            vector<vector<string>> vs;
            vector<string> v;
        
            
            dfs(s, 0, vs, v);
            for(auto vec: vs){
                int tot=0;
                for(auto str: vec){
                    int num=stoi(str);
                    tot+=num;
                }
                if(tot==i){
                    ans+=(i*i);
                    break;
                }
            }
        }
        
        return ans; 
    }
};