class LRUCache {
private:
  typedef pair<int,int> pii;
  typedef list<pii>::iterator node_ptr;

  int capacity;
  list<pii> l;
  unordered_map<int, node_ptr> hash_table;
public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    l.clear(); hash_table.clear();
  }

  int get(int key) {
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

  void put(int key, int value) {
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

        l.push_front({key,value});
        hash_table[key] = l.begin();
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */