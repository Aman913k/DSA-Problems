class Solution {
public:
    bool  psblMinWeight(vector<int>& weights, int days, int W){
        int n=weights.size();
        
        int D=0;   
        int sum=0; 
        
        for(int i=0; i<n; i++){
    
            if(sum+weights[i]>W){
                D++;
                sum=weights[i];
            }
            else sum+=weights[i];
        }
          
        D++;
        return D<=days;    
    }
    
    
    int shipWithinDays(vector<int>& weights, int days) {
        int totSum=0;
        for(auto i: weights) totSum+=i;  
        
        int beg=*max_element(weights.begin(), weights.end()), end=totSum;   
        
        int ans;  
        while(beg<=end){
            int mid=beg+(end-beg)/2;    
            
            if(psblMinWeight(weights, days, mid)){
                ans=mid;
                end=mid-1;
            }
            else beg=mid+1;
        }
        return ans; 
    }
};