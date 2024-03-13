class Solution {
public:
    int pivotInteger(int n) {
        int prefSum=0;
        for(int i=1; i<=n; i++){
            int prefSum=i*(i+1)/2; 
            int k=i-1;  
            
            int suffSum=n*(n+1)/2-(k*(k+1)/2); 
            
            if(prefSum==suffSum) return i;
        }
        return -1;
    }
};