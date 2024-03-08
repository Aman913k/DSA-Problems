class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101);
        
        for(auto i: nums) freq[i]++;
        sort(freq.begin(), freq.end(), greater<int>()); 
        
         
        int cnt=freq[0]; 
        for(int i=1; i<nums.size(); i++){
            if(freq[i] && freq[i]==freq[i-1]) cnt+=freq[i];
            else break;
        }
        
        return cnt; 
    }
};