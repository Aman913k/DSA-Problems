class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        
        vector<int> temp=nums;
        sort(temp.begin(), temp.end());
        
        int i=0, j=n-1;
        int cnt=0;
        
        while(i<j){
            if(nums[i]==temp[i] && nums[j]==temp[j]){
                cnt+=2;
                i++;
                j--;
            }
            else if(nums[i]==temp[i]){
                cnt++;
                i++;
            }
            else if(nums[j]==temp[j]){
                cnt++;
                j--;    
            }
            else break;
        }
        if(i==j && nums[n/2]==temp[n/2]) cnt++;
        return n-cnt;   
         
    }
};