class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0,r=0;
        int n=nums.size();
        double avg; 
        double kk=k;
        
        for(r=0; r<k-1; r++){
            avg+=nums[r]/kk;
        }
        
        double maxi=INT_MIN;   
        while(r<n){
            avg+=nums[r]/kk; 
            maxi=max(maxi, avg);
            
            avg-=nums[l]/kk;
            r++;
            l++;  
        }
        return maxi; 
    }
};