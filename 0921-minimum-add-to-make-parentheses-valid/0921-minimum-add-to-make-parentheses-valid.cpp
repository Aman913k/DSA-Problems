class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int cnt=0;
        stack<char> st;
        
        for(int i=0; i<n; i++){
            if(!st.empty() && st.top()=='(' && s[i]==')'){
                st.pop();
                continue; 
            }
            else if(st.empty() && s[i]==')'){
                cnt++;
                continue; 
            }
            st.push(s[i]);
        }
        while(!st.empty()) cnt++, st.pop();
        return cnt; 
    }
};