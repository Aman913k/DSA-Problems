class Solution {
public:
    int maxVowels(string s, int k) {
        int l=0;
        int n=s.size();
        int cnt=0;
        
        for(int i=0; i<k-1; i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                cnt++;
            }
        }
        
        int r=k-1;
        int maxi=INT_MIN;  
            
        while(r<n){
            if(s[r]=='a'||s[r]=='e'||s[r]=='i'||s[r]=='o'||s[r]=='u') cnt++;
            
            maxi=max(maxi, cnt);
            if(s[l]=='a'||s[l]=='e'||s[l]=='i'||s[l]=='o'||s[l]=='u') cnt--;
            r++;
            l++;
        }
        return maxi;
    }
};