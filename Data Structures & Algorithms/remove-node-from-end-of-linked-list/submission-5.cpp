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
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            curr = curr->next;
            ++length;
        }
        
        int idx = length - n;
        ListNode* sentinel = new ListNode(-1);
        sentinel->next = head;
        ListNode* prev = sentinel;
        curr = head;
        while (idx) {
            prev = curr;
            curr = curr->next;
            --idx;
        }
        
        prev->next = curr->next;
        delete curr;


        return sentinel->next;
    }
};
