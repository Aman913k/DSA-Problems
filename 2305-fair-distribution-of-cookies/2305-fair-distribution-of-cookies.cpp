void helper(vector<int>& nums, vector<int>& v, int k, int indx, int &ans){
    if(indx>=nums.size()){
        int maxi=*max_element(v.begin(), v.end());
        if(maxi<ans) ans=maxi;
        return; 
    }
    
    for(int i=0; i<k; i++){
        v[i]+=nums[indx];
        helper(nums, v, k ,indx+1, ans);
        v[i]-=nums[indx];
    }
}




class Solution {
public:
    int distributeCookies(vector<int>& nums, int k) {
        vector<int> v(k);
        int ans=1e9;
        helper(nums, v, k, 0, ans);
        
        return ans;
    };
};