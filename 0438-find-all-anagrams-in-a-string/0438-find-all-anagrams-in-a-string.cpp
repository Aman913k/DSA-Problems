class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> smap(26,0), pmap(26,0);
        vector<int> ans;
        
        if(s.size()<p.size()) return {}; 
        
        for(int i=0; i<p.size(); i++){
            smap[s[i]-'a']++;
            pmap[p[i]-'a']++;
        }
        if(smap==pmap) ans.push_back(0);
        int l=0, r=p.size(); 
        
        while(r<s.size()){
            smap[s[r]-'a']++;
            smap[s[l]-'a']--;
            
            if(smap==pmap) ans.push_back(r+1-p.size());
            l++;
            r++;
        }
        return ans; 
    }
};