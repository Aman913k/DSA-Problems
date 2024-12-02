class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=sentence.size(); 
        string s;
        int cnt=1;
        for(int i=0; i<n; i++){
            if(i-1<0||sentence[i-1]==' '){
                string s;
                int j=i;
                while(j<n&&sentence[j]!=' ') s+=sentence[j++];
                int indx=s.find(searchWord);  
                if(indx==0) return cnt;
                cnt++;
            }      
        }
        return -1; 
    }
};