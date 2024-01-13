class Solution {
public:
    int minSteps(string s, string t) {
        map<int,int> mp1, mp2;
        
        for(int i=0; i<s.size(); i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        int cnt=0;
        if(mp1==mp2) return 0;
        for(auto i: mp1){
            cnt+=min(i.second, mp2[i.first]);
        }
        
        return s.size()-cnt;
        
    }
};