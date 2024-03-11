class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> occurS(26, 0);
        for(int i=0; i<s.size(); i++) occurS[s[i]-'a']++;
    
        string ans=""; 
        
        for(int i=0; i<order.size(); i++){
            int occurance=occurS[order[i]-'a'];
            occurS[order[i]-'a']=0; 
            
            while(occurance--){
                ans+=order[i];
            }
        }
        
        for(int i=0; i<occurS.size(); i++){
            if(occurS[i]){
                int occurance=occurS[i];
                occurS[i]=0;
                while(occurance--){
                    ans+=(i+'a');
                }
            }
        } 
        
        return ans;    
    }
};