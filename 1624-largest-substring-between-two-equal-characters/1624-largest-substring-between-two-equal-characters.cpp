class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxi=-1; 
        int n=s.size();
        vector<int> last(26);
        for(int i=0; i<n; i++) last[s[i]-'a']=i;
        
        for(int i=0; i<n; i++){  
            if(i!=last[s[i]-'a']) maxi=max(maxi, (last[s[i]-'a']-i-1));
        }
        
        return maxi;
    }
};