class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char> st;
        
        if(num.size()<=k) return "0"; 
        st.push(num[0]);
       
        for(int i=1; i<n; i++){
          
            while(!st.empty() && st.top()>num[i] && k>0){  
                k--;
                st.pop();        
            } 
            st.push(num[i]);
            if(st.size()==1 && num[i]=='0') st.pop();
        }
             
        while(!st.empty() && k>0){
            st.pop();
            k--; 
        }
        
        string ans="";  
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());   
        if(ans=="") return "0"; 
        return ans;
   
    }
};