/*
LRU CACHE->Least Recently Used Cache 
How it Works:

______________
|___|____|___|   <------Cache Size = 3

Initially Empty.
Let Our Page requests be [1,3,4,5,3].

1 is not present in the cache so its a cache miss. It get placed inot the cache.
 __ __ ____ ____
|_____|____|__1_|  <------1 gets place at the back of the cache.

similarly 3 and 4 are cache misses and will be the placed into the cache.

 __ __ ____ ____
|__4__|__3_|__1_|  <------3 and 4 gets place at the successive order of the cache.

Now when 5 comes in it again a cache miss but there is no locaction to place it.
Here the actual working of the LRU algorithm works.
It removes the LEAST RECENTLY USED element i.e the leftmost element.

 __ __ ____ ____
|__5__|_4__|__3_|  <------5 gets place at the front of the cache and 3 and 4 gets shifted to the right.

Now when 3 comes in its not a cache miss. but it is going to be recently used.The recently used elements 
are present at the leftmost side. so we shift all the elements to the left and place 3 at the leftmost location.

 __ __ ____ ____
|__3__|__5_|__4_|  <------3 gets place at the front of the cache.


So we can sum up and write the algorithm as such

For get function
1. If the element is not found we return -1.
2. If found we erase that element by making sure the relative locations of the other elements are intact.

For put function
1. If the element is found in the cache we erase it and put it back to the front(as it becomed the most recently used element).
2. If the element is not found there are 2 cases to look for:
   Case 2a: if the cache size if full remove the element and place it at the front of the cache.
   Case 2b: if the cache size is not full we simply place the element at the right location of the previously recently used element.

*/
class LRUCache {
private:
    int cache_size;
    deque<int> cache;
    unordered_map<int,int> map;
public:
    LRUCache(int capacity) {
        cache_size=capacity;
        cache.clear();
        map.clear();
    }
    
    int get(int key) {
        if(map.find(key)==map.end())return -1;
        deque<int>::iterator it=cache.begin();
        while(*it!=key)
        {
            it++;
        }
        cache.erase(it);
        cache.push_front(key);
        return map[key];
    }
    
    void put(int key, int value) {
        if(map.find(key)==map.end())
        {
            if(cache_size==cache.size())
            {
                int last=cache.back();
                cache.pop_back();
                map.erase(last);
            }
        }
        else
        {
            deque<int>::iterator it=cache.begin();
            while(*it!=key)it++;
            cache.erase(it);
            map.erase(key);
        }
        cache.push_front(key);
        map[key]=value;
    }
};
