class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int maxi=0;
        int cnt=1;
        int ans=arr[0];
        
        for(int i=1; i<arr.size(); i++){
            if(arr[i]==arr[i-1]){
                cnt++;
                if(cnt>maxi){
                    maxi=cnt;
                    ans=arr[i];
                }
            }
             
            else cnt=1;
            
        }
        return ans;
    }
};