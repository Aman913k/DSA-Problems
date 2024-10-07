class Solution {
public:
    int minLength(string s) {
        int n=s.size();
        int cnt=0;
        
        stack<char> st;
        for(int i=0; i<n; i++){  
              
            if(!st.empty()&&s[i]=='B'&&st.top()=='A'){
                cnt+=2;
                st.pop();
                continue;
            }
            if(!st.empty()&&s[i]=='D'&&st.top()=='C'){
                cnt+=2;
                st.pop();
                continue; 
            }
            
            st.push(s[i]);  
        }
        
        return n-cnt;
    }
};