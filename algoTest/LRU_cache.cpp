
class LRUCache{
public:
    struct entry{
        int key;
        int value;
        entry(int k, int v): key(k), value(v) {}
    };
    LRUCache(int capacity) {
        cacheSize = capacity;  
    }
    int get(int key) {
        if(cMap.find(key) != cMap.end()){
            MoveToHead(key);
            cMap[key] = cache.begin();
            return cache.begin()->value;
        }
        return -1;
    }
    void set(int key, int value) {
        if(cMap.find(key) != cMap.end()){
            MoveToHead(key);
            cache.front().value = value;
        }
        else{
            if(cache.size() >= cacheSize){
                cMap.erase(cache.back().key);
                cache.pop_back();
            }
            entry add(key, value);
            cache.push_front(add);
        }
        cMap[key] = cache.begin();
    }
private:
    unordered_map<int, list<entry>::iterator> cMap;
    list<entry> cache;
    int cacheSize;
    void MoveToHead(int key){
        entry add(key, cMap[key]->value);
        cache.erase(cMap[key]);
        cMap.erase(key);
        cache.push_front(add);
    }
};