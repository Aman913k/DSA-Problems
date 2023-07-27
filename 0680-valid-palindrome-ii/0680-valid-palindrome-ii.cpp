class Solution {
public:
    bool helper(string &s, int i, int j, int cnt){
        if(i>=j) return true;
        if(cnt>1) return false;
        if(s[i]!=s[j] && cnt>=1) return false;
        
        if(s[i]==s[j]) return helper(s, i+1, j-1, cnt);
        return helper(s, i+1, j, cnt+1)||helper(s, i, j-1, cnt+1);   
    }
    
    
    
    
    bool validPalindrome(string s) {
        int n=s.size();
    
        if(helper(s, 0, n-1, 0)) return true;
        return false; 
    }
};