bool comp(const vector<int>& a, const vector<int>& b){
    if(a[1]<b[1]) return true;
    else if(a[1]==b[1]) return a[0]<b[0];
    return false;;
}

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(), events.end(), comp);
        int cnt=0;
        
        int s=INT_MAX, e=0;
        for(auto i: events){
            s=min(s, i[0]);
            e=max(e, i[1]);
        }
        
        set<int> st;
        for(int i=s; i<=e; i++){
            st.insert(i); 
        }
       
        
        for(int i=0; i<n; i++){
            int start=events[i][0], end=events[i][1];
            auto it=st.lower_bound(start);
            
            if(it==st.end() || *it>end) continue;
            else{
                cnt++;
                st.erase(*it); 
            }
        }
        
        
        for(auto i: events) cout<<i[0]<<" "<<i[1]<<"  "; 
        
        return cnt;        
        
    }
};