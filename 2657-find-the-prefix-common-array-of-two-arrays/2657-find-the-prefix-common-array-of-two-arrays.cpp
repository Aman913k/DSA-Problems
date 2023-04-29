class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp;
        int cnt=0;
        
        vector<int> pref(A.size(), 0);
        mp[A[0]]++; 
        mp[B[0]]++;
        
        if(A[0]==B[0]){
            cnt++;
            pref[0]=1;
        }
        
        for(int i=1; i<A.size(); i++){
            if(mp[A[i]]&&mp[B[i]]){
                cnt+=2; 
                mp[A[i]]++;
                mp[B[i]]++;
                pref[i]=cnt;
            }
            else if((mp[A[i]]&&!mp[B[i]])||(!mp[A[i]]&&mp[B[i]])){
                cnt+=1;
                mp[A[i]]++;
                mp[B[i]]++;
                pref[i]=cnt;
            }
            
            else if(!mp[A[i]]&&!mp[B[i]]&&A[i]==B[i]){
                cnt+=1;
                mp[A[i]]++;
                mp[B[i]]++;
                pref[i]=cnt;
            }
            else if(!mp[A[i]]&&!mp[B[i]]){  
                mp[A[i]]++;
                mp[B[i]]++;
                pref[i]=cnt;
            }
            
        }
        return pref;  
    }
};  