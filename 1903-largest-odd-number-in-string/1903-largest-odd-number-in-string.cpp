class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int i;
        string s=""; 
        
        for(i=n-1; i>=0; i--) if((num[i]-'0')%2) break; 
        for(int j=0; j<=i; j++) s+=num[j];
        return s; 
    }
};