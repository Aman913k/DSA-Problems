class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> seen(26, 0);
        vector<int> last(26, 0);
        
        for(int i=0; i<s.size(); i++) last[s[i]-'a']=i;
        
        stack<char> st;
        
        for(int i=0; i<s.size(); i++){
            if(seen[s[i]-'a']) continue;  
             
            while(!st.empty() && st.top()>s[i]){
                char tp=st.top();
                if(last[tp-'a']>i){  
                    st.pop();
                    seen[tp-'a']=0; 
                }
                else break;
            }
            
            if(!seen[s[i]-'a']){
                st.push(s[i]);
                seen[s[i]-'a']=1;
            }
        
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop(); 
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
        
    }
};