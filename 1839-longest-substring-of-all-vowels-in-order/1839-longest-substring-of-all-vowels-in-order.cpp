class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int l=0, r=1;
        unordered_map<char, int> mp;
        int n=word.size();
        int maxi=0; 
        mp[word[0]]++;
        
        while(r<n){ 
            if(word[r]<word[r-1]){
                if(mp.size()==5){
                    cout<<"hello";
                    maxi=max(maxi, r-l);
                }
                mp.clear();
                l=r;
            }
            mp[word[r]]++;
            r++;
        }
        if(mp.size()==5) maxi=max(maxi, r-l); 
        return maxi;
    }
};