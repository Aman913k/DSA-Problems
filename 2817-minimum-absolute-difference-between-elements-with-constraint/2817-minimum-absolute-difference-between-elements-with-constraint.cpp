class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n=nums.size();
        
      
        set<int> st;
        int mini=INT_MAX;
        for(int i=x; i<n; i++){
            st.insert(nums[i-x]); 
            auto it=st.upper_bound(nums[i]);

            if(it!=st.end()) mini=min(mini, abs(nums[i]-*it));
            if(it!=st.begin()) mini=min(mini, abs(nums[i]-*prev(it)));
        }
        
        return mini;  
        
    }   
        
};