class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        
        int prev=arr[0];  
        for(int i=1; i<n; i++){
            if(arr[i]>prev){
                prev=arr[i];
                continue;
            }
            else return i-1;
        }
        return 0;
    }
};