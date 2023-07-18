class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size();
        vector<int> v; 
        
        int carry=0;   
        for(int i=n-1; i>=0; i--){
            int l=0;
            if(k>0){
                l=k%10;
                k/=10;  
            }
            v.push_back((l+num[i]+carry)%10);
            
            carry=(l+num[i]+carry)/10;
        
        }
        
        k+=carry;
        while(k>0){
            v.push_back(k%10);
            k/=10;
        }
        reverse(v.begin(), v.end());
        
        return v;
    }
};