class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> st1, st2;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='#' && !st1.empty()) st1.pop();
            else if(s[i]=='#' && st1.empty()) continue;
            else st1.push(s[i]);
        }
           
        for(int i=0; i<t.size(); i++){
            if(t[i]=='#' && !st2.empty()) st2.pop();
            else if(t[i]=='#' && st2.empty()) continue;
            else st2.push(t[i]);
        }
         
        string s1="",s2="";
        
        while(!st1.empty()){
            s1+=st1.top();
            st1.pop(); 
        }
        
        while(!st2.empty()){
            s2+=st2.top();
            st2.pop();
        }
        
        cout<<s1<<" "<<s2;
        
        return s1==s2;  
    }
};