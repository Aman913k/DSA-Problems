class Solution {
public:
    bool check(vector<int>& time, int totalTrips, long long mid){
        int i=0, n=time.size();
        long long total=0;
        
        while(i<n){  
            total+=mid/time[i];
            if(total>=totalTrips) return true;
            i++;   
        }
        return (total>=totalTrips)? true: false;   
    }
    
    
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long beg=1, end=*min_element(time.begin(), time.end())*(long)totalTrips;
          
        while(beg<=end){
            long long mid=beg+(end-beg)/2;
            if(check(time, totalTrips, mid)) end=mid-1;
            else beg=mid+1;
        }
        return beg;
    }
};