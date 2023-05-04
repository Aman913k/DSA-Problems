class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int i=1;
        int maxi=gain[0];    
        int curr=gain[0]; 
         
        while(i<n){        
            if(gain[i]+curr>maxi) maxi=gain[i]+curr;
            curr+=gain[i]; 
            i++;  
        }
        if(maxi<0) return 0; 
        return maxi;  
    }
};