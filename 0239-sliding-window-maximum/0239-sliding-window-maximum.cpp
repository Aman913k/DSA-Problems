class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;
        int n=nums.size();
        vector<int> ans;
        
        int t=0;
        for(int i=0; i<n; i++){
            t++;
            st.insert(nums[i]);
            
            if(t==k){
                ans.push_back(*st.rbegin());
                t--;
                
                auto pos=st.find(nums[i-(k-1)]); 
                st.erase(pos);
                //cout<<nums[i-(k-1)]<<" ";
            }
        }
    
        return ans;  
    }
};