class Solution {
public:
    bool canReach(vector<int>& dist, double hour, int speed){
        double timeTaken=0;
        int n=dist.size();
        
        for(int i=0; i<n; i++){  
            double t=(double(dist[i])/double(speed));
            if(i!=n-1) timeTaken+=ceil(t);
            else timeTaken+=t;
        }        
        if(timeTaken<=hour) return true;  
        return false;
    }
    
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        double canReachHour=0;
        int n=dist.size();
        
        int beg=1, end=1e7;
        
        while(beg<=end){
            int mid=beg+(end-beg)/2;
             
            if(canReach(dist, hour, mid)) end=mid-1;
            else beg=mid+1;
        }
        if(beg>1e7) return -1;
        
        return beg;
    }
};