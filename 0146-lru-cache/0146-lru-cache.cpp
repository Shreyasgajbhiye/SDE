class LRUCache {
public:
    // vector<pair<int, int>> cache;
    // int n;
    // LRUCache(int capacity) {
    //     n = capacity;
    // }
    
    // int get(int key) {
    //     for(int i=0;i<cache.size();i++){
    //         if(cache[i].first == key){
    //             pair<int, int> temp = cache[i];
    //             int val = temp.second;
    //             cache.push_back(temp);
    //             cache.erase(cache.begin() + i);
    //             return val;
    //             // cache.push_back(temp);
    //             // return cache[i].second;
    //         }
    //     }
    //     return -1;
    // }
    
    // void put(int key, int value) {
    //     for(int i=0;i<cache.size();i++){
    //         if(cache[i].first == key){
    //             pair<int, int> temp = cache[i];
    //             cache.erase(cache.begin() + i);
    //             cache.push_back({key, value});
    //             return;
    //         }
    //     }

    //     if(n == cache.size()){
    //         cache.erase(cache.begin());
    //         cache.push_back({key, value});
    //     }
    //     else{
    //         cache.push_back({key, value});
    //     }
    // }

    map<int, pair<list<int>::iterator, int>> mp;
    list<int> dll;
    int n;
    LRUCache(int capacity){
        n = capacity;
    }

    void mostRecent(int key){
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }

    int get(int key){
        if(mp.find(key) == mp.end()){
            return -1;
        }

        mostRecent(key);
        return mp[key].second;
    }

    void put(int key, int value){
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            mostRecent(key);
        }else{
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }

        if(n < 0){
            int tobedel = dll.back();
            mp.erase(tobedel);
            dll.pop_back();
            n++;
        }
    }


};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */