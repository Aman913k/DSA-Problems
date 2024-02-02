class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;  
        string s=to_string(low);
        int n=s.size(); 
        
        int num=1, diff=1;
        int sz=n+1; 
        for(int i=2; i<=n; i++){
            num=(num*10)+i;   
            diff=(diff*10)+1;       
        }
        
        int start=num;   
        while(start<=high){
            
            if(start>=low) ans.push_back(start);
            start+=diff;
            
            if(start%10==0){      
                start=(num*10)+sz;
                diff=(diff*10)+1;
                num=(num*10)+sz; 
                sz++; 
            }
               
        }
        
        return ans;     
    }
};