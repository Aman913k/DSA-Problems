class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0; i<l.size(); i++){
            vector<int> v;
            int fg=0;
            
            for(int j=l[i]; j<=r[i]; j++) v.push_back(nums[j]);
            sort(v.begin(), v.end());
            int diff=v[1]-v[0]; 
                       
            for(int i=1; i<v.size(); i++){
                if(v[i]-v[i-1]!=diff){
                    fg=1;
                    break;
                }
            }
            
            if(!fg) ans.push_back(true);
            else ans.push_back(false); 
        }
        
        return ans; 
    }
};