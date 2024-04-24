class Solution {
public:
    int tribonacci(int n) {
        if(n<=0) return 0;
        if(n<=2) return 1;
        
        vector<int> fibos(n+1); 
        fibos[1]=1, fibos[2]=1;
        
        for(int i=3; i<=n; i++) fibos[i]=fibos[i-1]+fibos[i-2]+fibos[i-3];
        
        return fibos[n];
   
    }
};