struct node{
    int key, val;
    node* next;
    node* prev;

    node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, node*> cache;
    node* left;
    node* right;

    void remove(node* n){
        node* nxt = n->next;
        node* prv = n->prev;
        prv->next = nxt;
        nxt->prev = prv;
    }

    void insert(node* n){
        node* prv = right->prev;
        prv->next = n;
        n->prev = prv;
        n->next = right;
        right->prev = n;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        right = new node(0,0);
        left = new node(0,0);

        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        
        node* n = cache[key];
        remove(n);
        insert(n);
        return n->val;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            cache[key]->val = value;
            remove(cache[key]);
            insert(cache[key]);
            return;
        }

        node* n = new node(key,value);
        insert(n);
        cache[key] = n;

        if(cache.size()>cap){
            node* rmv = left->next;
            cache.erase(rmv->key);
            remove(rmv);
            delete rmv;
        }
    }
};