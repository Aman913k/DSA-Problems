class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        // return (numBottles)+(numBottles/numExchange);
        int tot=numBottles; 
        int i=0;
        
        while(numBottles>=numExchange+i){  
            numBottles-=(numExchange+i);
            if(numBottles>=0){
                tot++;
                numBottles++; 
            }
            i++;
        }
        
        return tot; 
    }
};