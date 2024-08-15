class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; i++){
            if(bills[i]==5) mp[bills[i]]++;
            else if(bills[i]==10){
                if(mp.find(5)==mp.end()) return false;
                mp[5]--;
                mp[10]++;
            }
            else if(bills[i]==20){
                if(mp[10]>=1 && mp.find(5)!=mp.end() && mp[5]>=1){
                    mp[10]--;
                    mp[5]--; 
                }
                else if( mp[5]>=3) mp[5]-=3;  
                else return false; 
            }
        }
        return true;  
    }
};