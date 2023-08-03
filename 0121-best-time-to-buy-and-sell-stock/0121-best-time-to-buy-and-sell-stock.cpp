class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        int j=n-2;
        int i=n-1;
        
        int maxi=prices[n-1];    // -->  4
        int maxProfit=0; 
        
        while(j>=0){  
            if(maxi-prices[j]>maxProfit){
                maxProfit=maxi-prices[j];     
            }
                 
            maxi=max(maxi, prices[j]);
            j--;       
        }
        
        return maxProfit;     
    }
};