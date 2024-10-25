class Solution {
public:
    vector<string> removeSubfolders(vector<string>& s) {
        sort(s.begin(), s.end());
        vector<string> ans;
        ans.push_back(s[0]);         
        
        for(int i=1; i<s.size(); i++){
            string root=ans[ans.size()-1]+"/";
            
            string pref=s[i].substr(0, root.size()); 
            cout<<pref<<endl;
              
            if(root!=pref) ans.push_back(s[i]);
        }
        return ans;
    }  
};   