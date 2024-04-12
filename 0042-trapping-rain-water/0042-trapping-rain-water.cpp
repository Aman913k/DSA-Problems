class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        stack<int> st;
        int water=0;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && height[i]>height[st.top()]){
                int tp=st.top();
                st.pop();
                if(st.empty()) break; 
                  
                int dis=i-st.top()-1;
                int hei=min(height[i], height[st.top()])-height[tp];
                
                water+=(dis*hei);
            }
            st.push(i); 
        }
        
        return water; 
    }
};