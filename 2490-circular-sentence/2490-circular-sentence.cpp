class Solution {
public:
    bool isCircularSentence(string sentence) {
        
        for(int i=0; i<sentence.size(); i++){
            if(sentence[i]==' ' && sentence[i-1]!=sentence[i+1]) return false;
        }
        if(sentence[0]==sentence[sentence.size()-1]) return true;
        return false;  
    }
};