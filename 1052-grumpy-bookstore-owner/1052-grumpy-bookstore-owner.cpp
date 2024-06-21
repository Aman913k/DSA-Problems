class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int n=grumpy.size(); 

        int sumAt0=0;
        for(int i=0; i<n; i++) if(grumpy[i]==0) sumAt0+=customers[i]; 
        
        int sum=0, maxi=0; 
        for(int i=0; i<n; i++) if(grumpy[i]==0) customers[i]=0; 
        for(int i=0; i<k; i++) sum+=customers[i];
        maxi=sum;
        for(int i=k; i<n; i++){
            sum+=customers[i];
            sum-=customers[i-k]; 
            
            maxi=max(maxi, sum); 
        }
        
        return sumAt0+maxi; 
    }
};