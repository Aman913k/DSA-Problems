#define ll long long
class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        map<char,int> mp;
        vector<int> Given(26);
        for(auto i: word2) Given[i-'a']++; 

        
        ll cnt=0;  
        ll l=0, r=0;
        int n=word1.size();
        
        ll ans=0;   
        while(r<n){
            mp[word1[r]]++;
        
            if(Given[word1[r]-'a']){
                if(mp[word1[r]]<=Given[word1[r]-'a']) cnt++;  
            }
            
            while(cnt==word2.size()){
                ans+=(n-r);    
                if(Given[word1[l]-'a']){
                    mp[word1[l]]--;
                    if(mp[word1[l]]<Given[word1[l]-'a']) cnt--; 
                }  
                l++;
            }
            
            r++;
        }
        
        return ans;
    }
};