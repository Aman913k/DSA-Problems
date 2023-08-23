class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        priority_queue<pair<int, char>> pq;
        
        for(auto i: s) mp[i]++;
        for(auto i: mp) pq.push({i.second, i.first});
        
        vector<char> v(n);
        int i=0, k=1;  
        
        while(!pq.empty()){
            int sz=pq.top().first;
            char ch=pq.top().second;
            pq.pop(); 
            
            if(2*sz-1>n) return "";    
            
            while(sz--){            
                if(i>=n){  
                    i=k;
                    k++;
                }
                
                v[i%n]=ch;
                i+=2;
             
            }
            
        }
        string ans="";
        for(auto i: v) ans+=i;
        return ans;  
        
    }
};