bool comp(const vector<int>& a, const vector<int>& b){
    if(a[0]==b[0]) return a[1]>b[1];
    return a[0]<b[0];
}  

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n=properties.size();
        sort(properties.begin(), properties.end(), comp);
        vector<int> end;
        for(auto i: properties) end.push_back(i[1]);  
        
        int cnt=0;
        int maxi=properties[n-1][1];   
        for(int i=n-2; i>=0; i--){  
            if(properties[i][1]<maxi) cnt++;
            maxi=max(maxi, properties[i][1]); 
        }
        
        return cnt;  
    }
};    