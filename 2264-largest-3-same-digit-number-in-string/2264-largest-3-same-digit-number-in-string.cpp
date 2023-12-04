class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        int maxi=-1;
        
        for(int i=2; i<n; i++){
            if(num[i]==num[i-1] && num[i-1]==num[i-2]) maxi=max(maxi, num[i]-'0');
        }
        if(maxi==-1) return "";
        return to_string(maxi)+to_string(maxi)+to_string(maxi);  
    }
};