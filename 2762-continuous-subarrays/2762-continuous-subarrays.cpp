#define ll long long 
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size(); 
        multiset<ll> st;
        ll l=0, r=0;                
        ll ans=0;  
        
        while(r<n){
            st.insert(nums[r]);
            
            while(!st.empty() && abs(*st.rbegin()-*st.begin())>2){
                st.erase(st.find(nums[l]));
                l++;  
            }           
             
            ans+=(r-l+1);
            r++; 
            
        }
        
        return ans; 
    }
};