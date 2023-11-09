class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> mp; 
        
        for(int i=1; i<n; i++){
            if(arr[0]>arr[i]){
                mp[arr[0]]++;
                if(mp[arr[0]]>=k) return arr[0];   
            }
            else{
                mp[arr[i]]++; 
                if(mp[arr[i]]>=k) return arr[i];
                swap(arr[0], arr[i]);  
            }
        }
        for(auto i: mp){
            if(i.second>=k) return i.first;
        }
        return arr[0];  
    }
};