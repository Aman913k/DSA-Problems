#define ll long long
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        ll n=nums.size();
        
        ll S=0, S2=0;  
        ll Sn=n*(n+1)/2;
        ll S2n=n*(n+1)*(2*n+1)/6;
        
        for(int i=0; i<n; i++){
            S+=nums[i];
            S2+=(nums[i]*nums[i]); 
        }
        
        ll a=S-Sn;
        ll b=S2-S2n;  
        
        ll c=b/a;
        ll repeating=(a+c)/2;
        ll missing=repeating-a;    
        
        return{(int)repeating, (int)missing}; 
        
    }
};