class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxi=-1; 
        int n=s.size(); 
        for(int i=0; i<n; i++){
            char ch=s[i];
            for(int j=n-1; j>=i; j--){
                if(s[j]==ch){
                    maxi=max(maxi, j-i-1);
                    break;
                } 
            }
        }
        return maxi;
    }
};