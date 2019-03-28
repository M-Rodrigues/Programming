#include<list>
typedef pair<int,int> pii;
typedef list<pii>::iterator node_ptr;

int capacity;
list<pii> l;
unordered_map<int, node_ptr> hash_table;

LRUCache::LRUCache(int size) {
    capacity = size;
    l.clear(); hash_table.clear();
}

int LRUCache::get(int key) {
    // key not in cache
    if (hash_table.count(key) == 0) return -1;

    // key in cache
    node_ptr node = hash_table[key];
    int val = node->second;
    l.erase(node);
    l.push_front({key, val});
    hash_table[key] = l.begin(); 
    
    return val;
}

void LRUCache::set(int key, int value) {
    // key in cache
    if (hash_table.count(key) > 0) {
        node_ptr node = hash_table[key];
        l.push_front({key, value});
        l.erase(node);
        hash_table[key] = l.begin(); 
    } else {
    // key not in cache
        // cache full
        if (l.size() == capacity) {
            node_ptr tail = --(l.end());
            hash_table.erase(tail->first);
            l.erase(tail);
        }
        // cache not full
        l.push_front({key,value});
        hash_table[key] = l.begin();
    }
}
