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
    
    
    
    int nextGreater(vector<int>& nums, int indx1){
        int indx=-1; 
        
        for(int i=nums.size()-1; i>indx1; i--){
            if(nums[i]>nums[indx1]){
                indx=i;
                break;
            }  
        }
        return indx;
    }
    
    
    
    void nextPermutation(vector<int>& nums) {
        
        int indx1=findBreak(nums);
        if(indx1==-1) reverse(nums.begin(), nums.end());
        
        else{
            int indx2=nextGreater(nums, indx1);
            swap(nums[indx1], nums[indx2]);
            reverse(nums.begin()+indx1+1, nums.end());
        }
        
        //cout<<indx1<<" "<<indx2<<"   ";  
    }
};