class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        string t=""; 
        
        for(int i=0; i<s.size(); i++){
            if(!st.empty() && abs(st.top()-s[i])==32){
                st.pop();
                continue;
            }
            else st.push(s[i]);
        }
        
        while(!st.empty()){
            t+=st.top();
            st.pop();
        }
        
        reverse(t.begin(), t.end());
        return t; 
    }
};  