class LRUCache {
private:
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    list<pair<int, int>> cache;
    int cap;

public:
    LRUCache(int capacity) {
        cap = capacity;
        hash.reserve(capacity);
        hash.max_load_factor(999999.0);
    }

    int get(int key) {
        if (hash.find(key) == hash.end()) {
            return -1;
        }

        // Move the accessed node to the front (Most Recently Used)
        cache.splice(cache.begin(), cache, hash[key]);

        return hash[key]->second;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        // If key already exists
        if (hash.find(key) != hash.end()) {
            hash[key]->second = value;
            cache.splice(cache.begin(), cache, hash[key]);
            return;
        }

        // Remove Least Recently Used if cache is full
        if (cache.size() == cap) {
            int lruKey = cache.back().first;
            hash.erase(lruKey);
            cache.pop_back();
        }

        // Insert new node at the front
        cache.push_front({key, value});
        hash[key] = cache.begin();
    }
};