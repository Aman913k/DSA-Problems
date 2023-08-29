class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt=numBottles;
        
        while(numBottles>=numExchange){
            cnt+=numBottles/numExchange;    

            int left=numBottles%numExchange;
            int empty=numBottles/numExchange;
            
            numBottles=left+empty;
        }
        
        return cnt;     
    }
};