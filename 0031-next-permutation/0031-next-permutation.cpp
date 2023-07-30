class Solution {
public:
    int findBreak(vector<int>& nums){
        int n=nums.size(); 
        int indx=-1;
        
        for(int i=n-1; i>0; i--){
            if(nums[i]>nums[i-1]){
                indx=i-1;
                break;
            }
        }
        return indx;
    }  
    
    int nextGreater(vector<int>& nums, int maxiIndx){
        int num=nums[maxiIndx];
        int mini=INT_MAX;
        int indx=-1; 
        
        for(int i=maxiIndx+1; i<nums.size(); i++){
            if(nums[i]>num && nums[i]<=mini){
                mini=nums[i];
                indx=i;
            }  
        }
        
        return indx;
       
    }  
    
    
    void nextPermutation(vector<int>& nums) {
        int indx2=0;
        int indx1=findBreak(nums);
        if(indx1>=0) indx2=nextGreater(nums, indx1);
        
        if(indx1==-1) reverse(nums.begin(), nums.end());
        
        else{
            swap(nums[indx1], nums[indx2]);
            reverse(nums.begin()+indx1+1, nums.end());
        } 
        
        
        cout<<indx1<<" "<<indx2<<"   ";
        
    }
};