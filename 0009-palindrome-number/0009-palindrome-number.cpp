class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        
        int n=x;
        long long num=0;
        
        while(n>0){
            long long r=n%10;
            num=(num*10)+r;
            n/=10;
        }  
        if(x==num) return true;
        return false;  
    }
};