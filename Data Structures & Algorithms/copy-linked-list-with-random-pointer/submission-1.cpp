/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> hashMap;
        Node* curr = head;
        while (curr) {
            hashMap[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        Node* newHead = hashMap[head];
        while (curr) {
            if (curr->next) hashMap[curr]->next = hashMap[curr->next];
            if (curr->random) hashMap[curr]->random = hashMap[curr->random];
            curr = curr->next;
        }
        return hashMap[head];

    }
};
