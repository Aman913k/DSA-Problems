class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
    
        for(int i=0; i<s.size(); i++){
            if(!st.empty() && s[i]==']' && st.top()=='[') st.pop(); 
            
            else if(st.empty() && s[i]==']'){
                st.push('[');
                continue;
            }
            
            else st.push(s[i]);
        }
         
        int cnt=0;
        while(!st.empty()) cnt++, st.pop(); 
        return cnt/2; 
    }
};