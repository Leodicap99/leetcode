class LRUCache {
public:
    unordered_map<int,list<int>::iterator> pos;
    unordered_map<int,int> map;
    int size;
    list<int> l;
    LRUCache(int capacity) {
        size=capacity;
    }
    void use(int key)
    {
        if(pos.find(key)!=pos.end())
            l.erase(pos[key]);
        else
        {
            if(l.size()>=size)
            {
                int old=l.back();
                l.pop_back();
                map.erase(old);
                pos.erase(old);
            }
        }
        l.push_front(key);
        pos[key]=l.begin();
    }
    int get(int key) {
        if(map.find(key)!=map.end())
        {
            use(key);
            return map[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        use(key);
        map[key]=value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
