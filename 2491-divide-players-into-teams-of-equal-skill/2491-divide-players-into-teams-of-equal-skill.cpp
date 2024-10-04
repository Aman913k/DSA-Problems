#define ll long long 
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        ll n=skill.size();
        
        ll tot=0; 
        unordered_map<ll,ll> mp;
        for(auto i: skill) tot+=i, mp[i]++; 
        
        ll tar=(tot*2)/n;
        ll ans=0; 
        
        for(int i=0; i<n; i++){
            if(skill[i]>=tar) return -1;
            if(mp.find(tar-skill[i])!=mp.end()){
                ans+=(skill[i]*(tar-skill[i]));
                mp[tar-skill[i]]--;
                if(mp[tar-skill[i]]==0) mp.erase(tar-skill[i]); 
            }  
            else return -1;
        }  
        return ans/2; 
    }
};