class Solution {
public:
    bool check(vector<int>& ranks, int cars, long long mid){
        int i=0, n=ranks.size();
        long long repaired_cars=0;
        
        while(i<n){
            repaired_cars+=sqrt(mid/ranks[i]);
            i++;
        }
        return (repaired_cars>=cars)? true : false;
    }
    
    
    long long repairCars(vector<int>& ranks, int cars) {
        long long beg=1, end=1e14;
        int repaired_cars=0;
        
        while(beg<=end){
            long long mid=beg+(end-beg)/2;
            if(check(ranks, cars, mid)){
                end=mid-1;
            }
            else beg=mid+1;
        }
        return beg;
    }
};