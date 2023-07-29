class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        
        string isPal;   
        for(int i=0; i<n; i++){
            if(s[i]-0>=97 && s[i]-0<=122) isPal+=tolower(s[i]);  
            else if(s[i]-0>=65 && s[i]-0<=90) isPal+=tolower(s[i]); 
            else if(s[i]-'0'>=0 && s[i]-'0'<=9) isPal+=s[i]; 
        }
          
        int i=0, j=isPal.size()-1;
        cout<<isPal<<" ";  
        
        while(i<j){
            if(isPal[i]!=isPal[j]) return false;
            i++;
            j--;
        }
        
        return true;    
    }
};