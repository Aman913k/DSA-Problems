class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        int cnt=0;
        map<char,int> mp, vis;
      
          
        for(int i=0; i<n; i++){
            if(vis[word[i]]==-1) continue; 
            if(word[i]>=65 && word[i]<=90){
                if(mp.find(word[i]+32)!=mp.end()) mp[word[i]+32]++; 
            }
            else if(word[i]>=97 && word[i]<=122){ 
                if(mp.find(word[i]-32)!=mp.end()) vis[word[i]]=-1;  
            }
            mp[word[i]]++;  
        }
        
        for(auto i: mp){
            if(i.first>=97 && i.first<=122 && mp[i.first-32]>0 && vis[i.first]!=-1) cnt++; 
        }
         
        return cnt;
        
        
    }
};