class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();    
        int sum=0;
    
        
        for(int i=0; i<n; i++){
            int oddLengthSum=0; 
            for(int j=i; j<n; j++){
                oddLengthSum+=arr[j];  
                if((j-i+1)%2==1){
                    sum+=oddLengthSum;
                }  
            }
        }
        
        return sum; 
    }
};