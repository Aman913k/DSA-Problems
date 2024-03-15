class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;     
        int neg=0;  
        int prefProd=1; 
        
        if(n==1) return nums[0];  
        
        for(int i=0; i<n; i++){       
            prefProd*=nums[i];
            if(prefProd==0){  
                prefProd=1;
                neg=0; 
            }
            else if(prefProd<0){
                if(neg==0) neg=prefProd;
                else maxi=max(maxi, prefProd/neg);
            }
            else maxi=max(maxi, prefProd); 
        }
        
        return maxi; 
    }
};