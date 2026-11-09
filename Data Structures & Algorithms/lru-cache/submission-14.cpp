class LRUCache {
public:
    struct Node {
        Node* next;
        Node* prev;
        int val;
        int key;

        Node(Node* next, Node* prev, int val, int key) {
            this->next= next;
            this->prev = prev;
            this->val = val;
            this->key = key;
        }
    };
    Node* sentinelHead;
    Node* sentinelTail;
    unordered_map<int, Node*> hash;
    int size;
    int cap;
    LRUCache(int capacity)
    : size(0)
    , cap(capacity) {
        sentinelHead = new Node(nullptr, nullptr, -1, -1);
        sentinelTail = new Node(nullptr, sentinelHead, -1, -1);
        sentinelHead->next = sentinelTail;
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end()) return -1;
        hash[key]->next->prev = hash[key]->prev;
        hash[key]->prev->next = hash[key]->next;
        sentinelHead->next->prev = hash[key];
        hash[key]->next = sentinelHead->next;
        sentinelHead->next = hash[key];
        hash[key]->prev = sentinelHead;
        return hash[key]->val;
    }
    
    void put(int key, int value) {
        if (hash.find(key) != hash.end()) {
            hash[key]->val = value;
            get(key);
            return;
        }
        ++size;
        if (size > cap) {
            Node* tmp = sentinelTail->prev;
            tmp->prev->next = tmp->next;
            sentinelTail->prev = tmp->prev;
            hash.erase(tmp->key);
            delete tmp;
            --size;
        }
        
        hash[key] = new Node(nullptr, nullptr, value, key);
        sentinelHead->next->prev = hash[key];
        hash[key]->next = sentinelHead->next;
        sentinelHead->next = hash[key];
        hash[key]->prev = sentinelHead;
    }
};
