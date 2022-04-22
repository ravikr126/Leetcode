class MyHashMap {
public:
    vector<vector<pair<int,int>>> buckets;
    int MOD = 1000;
    MyHashMap() {
        buckets.resize(MOD); 
    }
    
    void put(int key, int value) {
        int myKey = key % MOD;
        for(auto& thing : buckets[myKey]) {
            if(thing.first == key) {
                thing.second = value;
                return;
            }
        }
        buckets[myKey].push_back({key, value});
    }
    
    int get(int key) {
        int myKey = key % MOD;
        for(auto& thing : buckets[myKey]) {
            if(thing.first == key) {
                return thing.second;
            }
        }   
        return -1;
    }
    
    void remove(int key) {
        int myKey = key % MOD;
        int n = buckets[myKey].size();
        for(int i = 0; i < n; i++) {
            auto& thing = buckets[myKey][i];
            if(thing.first == key) {
                buckets[myKey].erase(buckets[myKey].begin() + i);
                return;
            }
        }
    }
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */