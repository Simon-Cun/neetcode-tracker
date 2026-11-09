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
        unordered_map<Node*, Node*> hash;
        Node* curr = head;
        while (curr) {
            hash[curr] = new Node(curr->val);
            curr = curr->next;
        }
        hash[nullptr] = nullptr;
        for (auto& i : hash) {
            if (i.first == nullptr) continue;
            i.second->next = hash[i.first->next];
            i.second->random = hash[i.first->random];
        }

        return hash[head];
    }
};
