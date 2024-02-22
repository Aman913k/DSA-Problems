class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int m=trust.size();
        unordered_map<int,int> mp, nope;
        
        if(m==0 && n==1) return n;  
        
        for(int i=0; i<m; i++){
            if(trust[i][0]!=trust[i][1]) mp[trust[i][1]]++;
            nope[trust[i][0]]++;  
        }
        
        for(int i=0; i<m; i++){
            for(auto i: mp) if(i.second==n-1 && nope[i.first]==0) return i.first;
        }
        return -1;  
    }
};