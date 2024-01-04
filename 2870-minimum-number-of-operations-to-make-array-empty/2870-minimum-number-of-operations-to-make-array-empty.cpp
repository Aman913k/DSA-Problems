class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(auto i: nums) mp[i]++;
        
        int cnt=0; 
        for(auto i: mp){
            if(i.second<2) return -1;     
            if(i.second%3==0) cnt+=i.second/3;  
            else if(i.second%3==1) cnt+=(i.second/3)-1+2;
            else cnt+=(i.second/3)+1;  
        }  
        
        return cnt;  
    }
};