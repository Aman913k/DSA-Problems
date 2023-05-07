class FrequencyTracker {
public:
    unordered_map<int, int> mp;
    unordered_map<int, int> freq;
    FrequencyTracker() {
    }
    
    void add(int number) {
        if(freq[mp[number]]>0) freq[mp[number]]--;     
        ++mp[number];  
        freq[mp[number]]++;
    }
    
    void deleteOne(int number) {
        if(mp[number]>0){    
            freq[mp[number]]--;
            mp[number]--;
            freq[mp[number]]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        if(freq[frequency]>0) return  true;
        return false; 
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */