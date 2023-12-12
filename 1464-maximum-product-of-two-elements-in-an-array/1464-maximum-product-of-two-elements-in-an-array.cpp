class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi1=0,maxi2=0;   
        maxi1=*max_element(nums.begin(), nums.end());
        int fg=0;
        for(auto i: nums){
            if(i==maxi1 && fg==0){
                fg=1;
                continue;
            }
            else maxi2=max(maxi2, i);
        }  
        return (maxi1-1)*(maxi2-1);
    }
};