class Solution {
public:
    int maximumSwap(int num) {
        string s;
        s=to_string(num); 
        string t=s; 
        int n=s.size();
        
        sort(s.begin(), s.end(), greater<int>());
        
        int maxi=0;    
        int falsiIndx=0;   
        for(int i=0; i<n; i++){
            if(s[i]!=t[i]){
                falsiIndx=i;  
                break; 
            }
        }
        
        for(int i=n-1; i>=0; i--){
            if(t[i]==s[falsiIndx]) swap(t[i], t[falsiIndx]);
        }
        
        int ans=0;
        for(int i=0; i<n; i++){
            ans=ans*10+(t[i]-'0');   
        }
        
        
        return ans;  
    
    }
};