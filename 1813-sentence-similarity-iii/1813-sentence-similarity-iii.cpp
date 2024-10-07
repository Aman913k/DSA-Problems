class Solution {
public:
    bool areSentencesSimilar(string sent1, string sent2) {
        vector<string> v1,v2; 
        string s;
        
        for(int i=0; i<sent1.size(); i++){
            if(sent1[i]==' '){
                v1.push_back(s);
                s="";
                continue;
            }
            s+=sent1[i]; 
        }
        v1.push_back(s);
        s=""; 
        
        for(int i=0; i<sent2.size(); i++){
            if(sent2[i]==' '){
                v2.push_back(s);
                s="";
                continue;
            }
            s+=sent2[i];  
        }
        v2.push_back(s);
        
        if(v1.size()<v2.size()) swap(v1, v2);   
      
        int i=0, n=v1.size(), m=v2.size(), j1=n-1, j2=m-1; 
        while(i<m&&i<n && v1[i]==v2[i]) i++;
        while(j1>=i && j2>=i && v1[j1]==v2[j2]){
            j1--;  
            j2--; 
        }
       
        if(j2<i) return true;
        return false; 
        
    }
};