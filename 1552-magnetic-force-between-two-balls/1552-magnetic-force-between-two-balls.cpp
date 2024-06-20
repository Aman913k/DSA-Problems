class Solution {
public:
    bool check(vector<int>& nums, int m, int mid){
        int cnt=1;  
        int x=nums[0]+mid; 

        while(1){  
            auto it=lower_bound(nums.begin(), nums.end(), x)-nums.begin();
        
            if(it<nums.size()){
                cnt++;
                x=nums[it]+mid; 
            } 
            else return false;
            if(cnt>=m) return true;
        }
        
      return false; 
    }
    
    
    int maxDistance(vector<int>& position, int m) {
        int n=position.size(); 
        sort(position.begin(), position.end());  
        
        int l=0, h=position[n-1]; 
        
        int ans=0; 
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(position, m, mid)){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        
        return ans;
    }
};