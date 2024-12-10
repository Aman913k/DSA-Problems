class Solution {
public:
    int maximumLength(string s) {
        int n=s.size(); 
        unordered_map<string, int> mp; 
        
        for(int i=0; i<n; i++){  
            string t="";
            for(int j=i; j<n; j++){ 
                t+=s[j];
                mp[t]++; 
            }
        }
        
        
        int ans=-1; 
        for(auto i: mp){
            if(i.second>=3){
                auto s1=i.first;
                int fg=0;
                for(auto i: s1) if(i!=s1[0]) fg=1;
                int sz=i.first.size();
                if(fg==0) ans=max(ans, sz); 
            }
        }
        
        return ans;
        
    }
};