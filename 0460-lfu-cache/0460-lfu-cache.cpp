class LFUCache {
public:
    int size;
    int cap;
    unordered_map<int, list<vector<int>>::iterator> mp;
    map<int, list<vector<int>>> freq;
    LFUCache(int capacity) {
        size = 0;
        cap = capacity;
    }
    
    void mostfrq(int key){
        auto &vec = *(mp[key]);
        int val = vec[1];
        int f = vec[2];

        freq[f].erase(mp[key]);
        if(freq[f].empty()){
            freq.erase(f);
        }

        f++;
        freq[f].push_front(vector<int> ({key, val, f}));
        mp[key] = freq[f].begin();
    }
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        auto &vec = *(mp[key]);
        int val = vec[1];
        mostfrq(key);
        return val;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(mp.find(key) != mp.end()){
            auto &vec = *(mp[key]);
            vec[1] = value;
            mostfrq(key);
        }
        else if(size < cap){
            size++;
            freq[1].push_front(vector<int> {key, value, 1});
            mp[key] = freq[1].begin();
        }
        else{
            auto &kaun_sa_list = freq.begin()->second;
            int del_key = kaun_sa_list.back()[0];
            kaun_sa_list.pop_back();

            if(kaun_sa_list.empty()){
                freq.erase(freq.begin()->first);
            }
            freq[1].push_front(vector<int>({key, value, 1}));
            mp.erase(del_key);
            mp[key] = freq[1].begin();

        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */