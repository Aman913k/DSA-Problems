class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        
        int l=1, h=n-1;  
        while(l<=h){
            int mid=l+(h-l)/2;
              
            int cnt=0;
            for(auto i: nums) if(i<=mid) cnt++;
            
            if(cnt<=mid) l=mid+1;
            else h=mid-1;
        }
        
        return l;
    }
};