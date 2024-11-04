class Solution {
public:
    string compressedString(string word) {
        int n=word.size(); 
        int cnt=1;
        string ans;   
        
        for(int i=1; i<n; i++){
            if(word[i]==word[i-1]) cnt++;
            if(cnt==9){  
                ans+=to_string(cnt);
                ans+=word[i-1];   
                cnt=0;   
            }  
            else if(word[i]!=word[i-1]){ 
                if(cnt>0)ans+=to_string(cnt);
                if(cnt>0)ans+=word[i-1];   
                cnt=1; 
            }  
        }
        if(cnt>0){
            ans+=to_string(cnt);
            ans+=word[n-1];
        }
        
        return ans;
    }
};