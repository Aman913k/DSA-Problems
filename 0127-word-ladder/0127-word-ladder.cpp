class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        
        q.push({beginWord, 1});
        s.erase(beginWord);
        
        while(!q.empty()){
            string word=q.front().first;
            int len=q.front().second;
            
            q.pop();
            if(word==endWord) return len;
            for(int i=0; i<word.length(); i++){
                char original=word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i]=ch;
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        q.push({word, len+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;  
    }
};