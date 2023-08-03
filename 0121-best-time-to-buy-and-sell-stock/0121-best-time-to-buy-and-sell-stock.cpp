class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        int j=n-2;
        
        int maxi=prices[n-1];    // -->  4
        int maxProfit=0; 
        
        while(j>=0){
            maxProfit=max(maxProfit, maxi-prices[j]);
                 
            maxi=max(maxi, prices[j]);
            j--;       
        }
        
        return maxProfit;     
    }
};