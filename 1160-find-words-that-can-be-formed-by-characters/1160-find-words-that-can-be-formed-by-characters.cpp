class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<int,int> mp1, mp2;
        for(auto i: chars){
            mp1[i]++;
            mp2[i]++;
        }
        int sum=0;
        
        for(int i=0; i<words.size(); i++){
            int fg=0;
            for(int j=0; j<words[i].size(); j++){
                if(!mp1[words[i][j]]){
                    fg=1;
                    break;
                }
                else mp1[words[i][j]]--;
            } 
            if(fg==0) sum+=words[i].size();
            mp1=mp2;
        }
        return sum;
    }
};