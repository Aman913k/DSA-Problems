class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int indx=0;
        int n=nums.size(); 
        vector<int>  ans;
         
        for(int i=1; i<n; i++){
            if(abs(nums[i])<=abs(nums[i-1])) indx=i;
            else break;
        }
        
        if(indx==0){
            for(int i=0; i<n; i++){
                ans.push_back(nums[i]*nums[i]);
            }
        }
        
        
        int i=indx, j=indx+1;  
        
        while(i>=0 && j<n && indx!=0){
            if(abs(nums[i])<abs(nums[j])){
                ans.push_back(nums[i]*nums[i]);
                i--; 
            }
            
            else{
                ans.push_back(nums[j]*nums[j]);
                j++; 
            }     
               
        }
        
        while(i>=0 && indx!=0){
            ans.push_back(nums[i]*nums[i]);
            i--; 
        }
        
        while(j<n && indx!=0){
            ans.push_back(nums[j]*nums[j]);
            j++; 
        }
        
        return ans; 
    }
};