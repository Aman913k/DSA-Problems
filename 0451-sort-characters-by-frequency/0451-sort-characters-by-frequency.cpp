class Solution {
public:
    string frequencySort(string s) {
        string t=""; 
        map<char, int> mp;
        for(auto ch: s) mp[ch]++;
        
        priority_queue<pair<int,char>> pq;
        
        for(auto m: mp) pq.push({m.second, m.first});
        
        while(!pq.empty()){
            int itr=pq.top().first;
            while(itr--) t+=pq.top().second;
            pq.pop(); 
        }
        
        return t;
    }
};