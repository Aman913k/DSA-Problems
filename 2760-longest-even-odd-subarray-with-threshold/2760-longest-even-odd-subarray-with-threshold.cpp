class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n=nums.size();
        int pair=0; 
        int cnt=0;
        
        for(int i=0; i<n; i++){
            if(nums[i]%2==0){
                int cnt=0; 
                for(int j=i; j<n-1; j++){  
                    
                    if((nums[j]%2 != nums[j+1]%2) && nums[j]<=threshold && nums[j+1]<=threshold){
                        cnt++;
                        pair=max(pair, cnt);
                    }
                    
                    else break;
                    
                }
            }
        }
        
        if(pair>0) return pair+1;
        
        if(pair==0){
            for(int i=0; i<n; i++){
                if(nums[i]%2==0 && nums[i]<=threshold) return 1;
            }
        }
        
        return pair;  
    }
};