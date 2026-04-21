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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* gap = head;
        for (int i = 0; i < n; ++i) {
            gap = gap->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (gap) {
            prev = curr;
            curr = curr->next;
            gap = gap->next;
        }
        if (prev == nullptr) {
            head = curr->next;
            delete curr;
            curr = nullptr;
        } else {
            prev->next = curr->next;
            delete curr;
            curr = nullptr;
        }
        
        return head;
    }
};
