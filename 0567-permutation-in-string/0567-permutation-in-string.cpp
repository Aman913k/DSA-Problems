class Solution {
public:
    bool checkInclusion(string s1, string s2) { 
        multiset<char> ms1, ms2;
        
        for(auto i: s1) ms1.insert(i);  
        
        int l=0, r=0; 
           
        while(r<s2.size()){
            ms2.insert(s2[r]);
            
            while(ms2.size()>ms1.size()){
                ms2.erase(ms2.find(s2[l]));
                l++;  
            }
            
            if(ms1==ms2) return true;
            
            r++;  
        }
        
        return false;
    }
};