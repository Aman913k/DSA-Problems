class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int,int> mp;
        for(auto i: s) mp[i]++;
        
        vector<int> v;
        for(auto i: mp) v.push_back(i.second);
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end()); 
        
        set<int> st;
        int cnt=0;
        
        for(auto i: v){
            if(st.find(i)==st.end()){
                st.insert(i);
            }
            else{ 
                int x=i;
                while(st.find(x)!=st.end()){  
                    x--;
                    if(x<0) break;
                    cnt++;
                }
                st.insert(x);      
            }
        }
        
        return cnt;
    }
};