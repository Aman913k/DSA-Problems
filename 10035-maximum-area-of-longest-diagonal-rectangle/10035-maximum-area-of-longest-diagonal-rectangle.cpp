class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        double maxArea=0, maxDiag=0, longDiagArea=0;
        
        set<pair<int,int>> st;
        for(auto i: dim){
            int a=i[0], b=i[1];
            if(a>b) swap(a, b);
            if(st.find({a,b})!=st.end()) continue;
            else st.insert({a,b}); 
        }
        vector<pair<int,int>> vp(st.begin(), st.end()); 
        
        for(auto i: dim){
            double l=i[0], b=i[1];
            maxArea=max(maxArea,(l*b));
            double x=sqrt((l*l)+(b*b));
            if(x>maxDiag){
                maxDiag=x;
                longDiagArea=(l*b);
            }
        }
        
        int fg=0, cnt=0;
        for(auto i: vp){
            double l=i.first, b=i.second;
            double x=sqrt((l*l)+(b*b));
            //cout<<x<<" "<<maxDiag<<endl;
            if(x==maxDiag){
                cnt++;
                if(cnt==2){
                    fg=1;
                    break;
                }
            }
        }
        
        if(fg==0) return longDiagArea;
        return maxArea;
    }
};