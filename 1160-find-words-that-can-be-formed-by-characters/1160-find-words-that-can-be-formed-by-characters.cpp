class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> mp;
        
        for(auto ch: chars) mp[ch]++;
        int sum=0;
        
        for(int i=0; i<words.size(); i++){
            string s=words[i];
            int fg=0;
            
            unordered_map<char, int> mp2;
            
            for(auto ch: s){     
                mp2[ch]++;       
            }
            
            for(auto i: mp2){
                if(mp[i.first]<i.second){
                    fg=1;
                    break;     
                }
            }
            if(fg==0) sum+=s.length();     
        }
        return sum;
    }
};