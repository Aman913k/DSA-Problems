class Solution {
public:

   int maxProduct(vector<int>& nums) {  
    int n=nums.size();  
	int maxi=INT_MIN, neg=0, prefProd=1;     
    
    for(int i=0; i<n; i++){       
        prefProd*=nums[i];
        maxi=max(maxi, prefProd);  
        
        if(prefProd==0){              // Whenever we encouner prefix product==0 just restart 
            prefProd=1;
            neg=0; 
        }
        else if(prefProd<0){
            if(neg==0) neg=prefProd;
            else maxi=max(maxi, prefProd/neg);
        }
    }
    
    return maxi; 
  }
};
