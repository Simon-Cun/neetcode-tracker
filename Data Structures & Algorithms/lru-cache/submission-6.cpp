struct Node {
    int key, val;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int capacity;
    Node* sentinelHead = new Node(-1, -1);
    Node* sentinelTail = new Node(-1, -1);
    unordered_map<int, Node*> hashMap;

    LRUCache(int capacity) : capacity(capacity) {
        sentinelHead->next = sentinelTail;
        sentinelTail->prev = sentinelHead;
    }

    void insertAtTail(Node* node) {
        node->prev = sentinelTail->prev;
        node->next = sentinelTail;
        sentinelTail->prev->next = node;
        sentinelTail->prev = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {
        if (hashMap.find(key) == hashMap.end()) return -1;
        Node* node = hashMap[key];
        removeNode(node);
        insertAtTail(node);
        return node->val;
    }

    void put(int key, int value) {
        if (hashMap.find(key) != hashMap.end()) {
            hashMap[key]->val = value;
            removeNode(hashMap[key]);
            insertAtTail(hashMap[key]);
        } else {
            Node* node = new Node(key, value);
            hashMap[key] = node;
            insertAtTail(node);
            if (hashMap.size() > capacity) {
                Node* lru = sentinelHead->next;
                removeNode(lru);
                hashMap.erase(lru->key);
                delete lru;
            }
        }
    }
};