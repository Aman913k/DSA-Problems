class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long cnt=0; 
        int l=0, r=0;
        int maxi=0, mini=0;        
          
        multiset<int> st;  
        
        while(r<n){
            st.insert(nums[r]);
            
            while(abs(*st.rbegin()-*st.begin())>2){
                st.erase(st.find(nums[l]));  
                l++;  
            }
            
            cnt+=(r-l+1);
            r++;
        }
        
        return cnt;  
    }
};