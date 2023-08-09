bool posbl(vector<int>& nums, int p, int diff){
    int k=0;
    for(int i=1; i<nums.size(); i++){
        if(nums[i]-nums[i-1]<=diff){
            k++;
            i++;
        }
    }
    if(k>=p) return true;
    return false;
}



class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
                
        int l=0, h=nums[n-1]-nums[0];
        
        while(l<=h){
            int mid=l+(h-l)/2;
              
            if(posbl(nums, p, mid)) h=mid-1;     
            else l=mid+1;
        }
        return l;           
    }
};