#define ll long long  
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll l=0, r=0, n=nums.size();
        ll cnt=0;
        ll score=0; 
        
        while(r<n) {
            score+=nums[r]; 
            
            while(score*(r-l+1)>=k){
                score-=nums[l]; 
                l++;
            }
            
            cnt+=(r-l+1); 
            r++;
        }
        
        return cnt;   
    }
};