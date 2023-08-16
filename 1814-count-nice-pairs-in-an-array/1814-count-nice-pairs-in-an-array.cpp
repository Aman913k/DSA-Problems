int rev(int n){
    int cnt=0;
    int num=0;
        
    while(n>0){
        int rem=n%10;   
        
        num=(num*10)+rem;
        n/=10;  
    }
    
    return num; 
}



class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        long long cnt=0;  
        
        for(int i=0; i<nums.size(); i++){
            cnt+=(mp[nums[i]-rev(nums[i])])%1000000007;
            
            mp[nums[i]-rev(nums[i])]++;
        }
        
        return cnt%1000000007; 
    }
};