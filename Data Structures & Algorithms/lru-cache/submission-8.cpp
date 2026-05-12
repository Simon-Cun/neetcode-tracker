struct Node {             
  int val;
  int key;
  Node* prev;
  Node* next;
  Node() : key(-1), val(-1), prev(nullptr), next(nullptr) {}
  Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
  Node(int key, int val, Node* prev, Node* next) : key(key), val(val), prev(prev), next(next) {}
};
class LRUCache {
public:
    int length;
    int maxLength;
    Node* sentinelHead;
    Node* sentinelTail;
    unordered_map<int, Node*> hashMap;
    LRUCache(int capacity) : length(0), maxLength(capacity) {
        sentinelHead = new Node(-1, -1);
        sentinelTail = new Node(-1, -1);
        sentinelHead->next = sentinelTail;
        sentinelTail->prev = sentinelHead;
    }
    
    int get(int key) {
        if (!hashMap.contains(key)) return -1;
        pushFront(hashMap[key]);
        return hashMap[key]->val;
    }
    
    void put(int key, int value) {
        if (hashMap.contains(key)) {
            pushFront(hashMap[key]);
            hashMap[key]->val = value;
            return;
        }
        if (length == maxLength) {
            hashMap.erase(sentinelTail->prev->key);
            pop(sentinelTail->prev);
            --length;
        }
        Node* toPush = new Node(key, value);
        hashMap[key] = toPush;
        pushFront(toPush);
        ++length;
    }

    void pushFront(Node* node) {
        if (node->prev and node->next) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        node->next = sentinelHead->next;
        node->prev = sentinelHead;
        node->next->prev = node;
        node->prev->next = node;
    }

    void pop(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        delete node;
    }
};
