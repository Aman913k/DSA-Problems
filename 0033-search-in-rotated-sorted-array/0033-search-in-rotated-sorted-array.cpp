int findBreak(vector<int>& nums){
    for(int i=1; i<nums.size(); i++){
        if(nums[i]<nums[i-1]) return i-1;
    }
    return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
          
        if(n==1){
            if(nums[0]!=target) return -1;
            return 0;  
        }
        
        int indx=findBreak(nums);
        
        int l=0, r=n-1;

        if(indx!=-1){
            if(target<=nums[indx] && target>=nums[0]){
                l=0;
                r=indx; 
            }
            
            else{
                l=indx+1;
                r=n-1;
                
            }
        }
        
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]<target) l=mid+1;
            else if(nums[mid]==target) return mid;     
            else r=mid-1;
        } 
        
        cout<<indx;
        if(nums[l]==target) return l;
        else if(nums[n/2]==target) return n/2;  
        return -1;
         
    }
};