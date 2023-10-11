char minChar(vector<int>& freq){ 
    for(int i=0; i<26; i++){
        if(freq[i]>0) return i+'a';
    }
    
    return '$'; 
}




class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);
        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']++;
        }
        
        stack<char> st;
        string ans="";  
        
        for(int i=0; i<s.size(); i++){
            char mini=minChar(freq);
            freq[s[i]-'a']--;
            
            while(!st.empty() && st.top()<=mini){
                ans+=st.top();
                st.pop(); 
            }
            
            st.push(s[i]);   
                
        }
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        return ans;   
        
        
        
    }
};