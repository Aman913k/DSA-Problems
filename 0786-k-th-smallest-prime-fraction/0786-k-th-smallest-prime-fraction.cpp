class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        
        priority_queue<pair<double, pair<double,double>>, vector<pair<double, pair<double,double>>>, greater<pair<double, pair<double,double>>>> pq; 
            
        for(int i=0; i<n; i++){        
            for(int j=i+1; j<n; j++){   
                pq.push({double(arr[i])/double(arr[j]), {arr[i], arr[j]}});
            }  
        }
        
        int x,y; 
        while(k--){
            auto tp=pq.top();   
            pq.pop();
            x=tp.second.first;
            y=tp.second.second;
        }  
        return{x, y}; 
    }
};