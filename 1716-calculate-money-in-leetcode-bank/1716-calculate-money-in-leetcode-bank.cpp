class Solution {
public:
    int totalMoney(int n) {
        int x=0;
        int t=1;
        int sum=0; 
        int itr=0;
        while(n--){
            if(x==7){
                x=0;
                itr++;
                t=itr+1;
            }
            x++;
            sum+=t;
            t++;
        }
        return sum; 
    }
};