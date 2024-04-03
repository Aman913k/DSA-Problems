class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        string s=to_string(x);
        int num=0;
        for(auto i: s) num+=(i-'0');
        
        cout<<num<<endl; 
        
        if(x%num==0) return num;     
        return -1;   
    }
};