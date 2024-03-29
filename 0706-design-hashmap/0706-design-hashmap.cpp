int N=1000001;
vector<int> v(N);
class MyHashMap {
public:
    MyHashMap() {
        v.clear();
        for(int i=0; i<N; i++) v[i]=-1; 
    }
    
    void put(int key, int value) {
        v[key]=value;
    }
    
    int get(int key) {
        if(v[key]==INT_MIN) return -1; 
        return v[key]; 
    }
    
    void remove(int key) {
        v[key]=INT_MIN;
    }
};
 
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */