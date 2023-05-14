class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        int xorr=0;
        
        for(int i=0; i<n; i++){
            xorr^=derived[i];
        }
        return xorr==0;
        
    }
};