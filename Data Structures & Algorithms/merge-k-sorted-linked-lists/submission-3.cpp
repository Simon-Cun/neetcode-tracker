/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct Comparison {
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comparison> pq;
        for (auto& i : lists) {
            if (i) {
                pq.push(i);
            }
        }
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while (!pq.empty()) {
            ListNode* toPush = pq.top();
            pq.pop();
            if (!head and !tail) {
                head = toPush;
                tail = toPush;
            } else {
                tail->next = toPush;
                tail = tail->next;
            }
            if (toPush->next) pq.push(toPush->next);
        }
        return head;
    }
};
