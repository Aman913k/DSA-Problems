class Solution {
public:
    int minimumDeletions(string s) {
        stack<int> st;
        int cnt=0; 
        
        for(int i=0; i<s.size(); i++){
            
            if(!st.empty() && st.top()>s[i]){
                st.pop();
                cnt++;
            }
           else st.push(s[i]);  
        }
        return cnt; 
    }
};