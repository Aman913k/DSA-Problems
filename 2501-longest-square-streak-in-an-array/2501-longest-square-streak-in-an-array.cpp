class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n=nums.size();
        set<int> s;
        int cnt=0, maxi=0;
        
        sort(nums.begin(), nums.end());
        for(auto n: nums) s.insert(n);
        
        for(auto n: nums){
            long long num=n;
            
            while(s.find(num)!=s.end()){
                cnt++;
                s.erase(num);
                num=num*num;
            }
            maxi=max(maxi,cnt);
            cnt=0;
        }
        
        return maxi<2?-1:maxi;
        
    }   
};