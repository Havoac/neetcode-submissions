class Node {
    public :
        int key, value;
        Node *prev;
        Node *next;

        Node(int _key, int _value) {
            key = _key;
            value = _value;
        }
};

class LRUCache {
public:
    unordered_map<int, Node *> cache;
    int capacity = 0;
    
    Node *head, *tail;

    LRUCache(int capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;

        this->capacity = capacity;
    }
    
    void Insert(int key, int value) {
        Node *node = new Node(key, value);

        Node *next = head->next;

        head->next = node;
        node->prev = head;

        node->next = next;
        next->prev = node;

        cache[key] = node;
    }

    void Delete(Node *node) {
        Node *prev = node->prev;
        Node *next = node->next;

        prev->next = next;
        next->prev = prev;

        cache.erase(node->key);
        
        // delete node;
    }

    int get(int key) {
        if(!cache.count(key))
        return -1;

        Node *node = cache[key];

        Delete(node);
        Insert(node->key, node->value);

        return cache[key]->value;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            Node *node = cache[key];

            Delete(node);
            Insert(key, value);
        }
        else 
        {
            if(cache.size() == capacity) 
            {
                Delete(tail->prev);
            }

            Insert(key, value);
        }
    }
};
