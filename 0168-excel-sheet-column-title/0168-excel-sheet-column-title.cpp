class Solution {
public:
    string convertToTitle(int N) {
        
        string s;   
        while(N>0){
            N--;
            int rem=N%26;
            s+='A'+rem;
            
            N/=26;  
        }
        
        reverse(s.begin(), s.end());
        return s;
        
    }
};