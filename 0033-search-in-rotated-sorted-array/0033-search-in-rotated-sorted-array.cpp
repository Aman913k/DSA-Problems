int findBreak(vector<int>& nums){
    int l=0, r=nums.size()-1;
    
    while(l<r){
        int mid=(l+r)/2;
        if(nums[mid]>nums[r]) l=mid+1;
        else r=mid;
    }   
    return l-1;
}


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();   
        
        int indx=findBreak(nums);
        int l=0, r=n-1;
        
        if(indx!=-1){    // Array is Rotated   
            if(target<=nums[indx] && target>=nums[0]){            
                l=0; 
                r=indx;
            }
            else{
                l=indx+1;
                r=n-1;
            }
        }
        
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) l=mid+1;
            else r=mid-1;
        } 
        
        return -1;   
    }
};