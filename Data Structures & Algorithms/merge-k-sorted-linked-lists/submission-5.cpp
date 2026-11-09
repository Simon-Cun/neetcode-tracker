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

class Solution {
public:
    struct Cmp {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
        ListNode* ret = nullptr;
        ListNode* tail = nullptr;
        for (auto& i : lists) {
            if (i) pq.push(i);
        }
        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();
            if (curr->next) pq.push(curr->next);
            if (ret == nullptr) {
                ret = curr;
                tail = curr;
            } else {
                tail->next = curr;
                tail = tail->next;
            }
        }
        return ret;
    }
};
