bool psbl(vector<int>& candies, long long k, int cands){
    long long cnt=0;
    
    for(int i=0; i<candies.size(); i++) cnt+=candies[i]/cands;
    return cnt>=k;
}     



class Solution {   
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l=1;
        int h=*max_element(candies.begin(), candies.end());
    
        
        while(l<=h){
            int mid=l+(h-l)/2;
            if(mid==0) return 0;
            
            if(psbl(candies, k, mid)) l=mid+1;   
            else h=mid-1;
        }
        
        return l-1;
    }
};