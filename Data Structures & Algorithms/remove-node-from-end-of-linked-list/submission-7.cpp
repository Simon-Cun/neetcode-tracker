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
        int size = 0;
        ListNode* curr = head;
        while (curr) {
            curr = curr->next;
            ++size;
        }
        ListNode* sentinelHead = new ListNode(-1, head);
        int pos = size - n;
        ListNode* prev = sentinelHead;
        curr = head;
        while (pos) {
            prev = curr;
            curr = curr->next;
            --pos;
        }
        prev->next = curr->next;
        delete curr;
        return sentinelHead->next;
    }
};
