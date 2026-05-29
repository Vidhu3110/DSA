class LRUCache {
public:
    int cap;
    unordered_map<int, list<pair<int,int>> :: iterator > mp;
    list<pair<int,int>> l;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!mp.count(key)){
            return -1;
        }
        l.splice(l.begin(),l,mp[key]);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            mp[key]->second = value;
            l.splice(l.begin(),l,mp[key]);
        }
        else{
            if(cap == mp.size()){
                auto lru = l.back();
                mp.erase(lru.first);
                l.pop_back();
            }
            l.push_front({key,value});
        mp[key] = l.begin();
        }
    }
};
