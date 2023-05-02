class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cntPos=0, cntNeg=0, cntZero=0;
        
        for(auto i: nums){
            if(i>0) cntPos++;
            else if(i<0) cntNeg++;
            else cntZero++; 
        }
        if(cntZero>0) return 0;
        if(cntNeg%2==0) return 1;
        return -1;  
    }
};