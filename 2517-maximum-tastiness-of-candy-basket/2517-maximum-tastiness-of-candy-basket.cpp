bool check(vector<int>& price, int k, int mid){
    int cnt=1;
    int indx=1;
    int prev=price[0];
    
    while(indx<price.size()){ 
        if(price[indx]-prev>=mid){
            cnt++;  
            prev=price[indx];
        }
        indx++; 
    }
    
    return cnt>=k; 
} 
  


class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        
        int l=0, h=1e9+1;
        int ans=0; 
        
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(check(price, k, mid)){
                ans=mid;
                l=mid+1; 
            }
            else h=mid-1;
        }  
        
        return ans;
    }
};