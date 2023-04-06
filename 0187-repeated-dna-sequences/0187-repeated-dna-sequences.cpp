class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        int n=s.size();
        int l=0, r=0, cnt=0;
        string st="";    
        
        while(r<n){
            st+=s[r];   
            cnt++;
            
            if(cnt==10){ 
                cnt--;
                mp[st]++;  
                l++;
                st.erase(st.begin());
            }
            r++;  
        }
        
        vector<string> ans;
        for(auto &i: mp){
            if(i.second>1) ans.push_back(i.first);
        }
        return ans;
    }
};