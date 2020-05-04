#include<bits/stdc++.h>

using namespace std;

//Design and implement a data structure for Least Recently Used (LRU) cache.
// It should support the following operations: get and put.

//get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//put(key, value) - Set or insert the value if the key is not already present.
// When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

class LRUCache {
public:
    int capacity;
    // list of pair
    list<pair<int,int>> l;
    // map of key and list
    unordered_map<int,list<pair<int,int>>::iterator> m;

    LRUCache(int capacity) {
        // set capacity
        this->capacity = capacity;
    }
    
    int get(int key) {
        // find key in map
        if(m.find(key) == m.end()){
            return -1;
        }

        // transfer element ??
        l.splice(l.begin,l,m[key]);

        // return value for key
        return m[key]->second;
    }
    
    void put(int key, int value) {
        // check key
        if(get(key)!=-1){
            // set valur for key
            m[key]->second=value;
            return;
        }

        // check capacity
        if(l.size() == capacity){
            // if capacity reached
            // erase least recently used element
            m.erase(l.back().first);
            // remove last element
            l.pop_back();
        }

        // add pair to list
        l.push_front(make_pair(key,value));

        // add element to map
        m[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    LRUCache l(5);

    return 0;
}