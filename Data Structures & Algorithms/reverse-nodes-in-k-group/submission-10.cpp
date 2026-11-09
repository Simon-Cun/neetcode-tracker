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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;
        while (curr) {
            curr = curr->next;
            n++;
        }

        ListNode* dummy = new ListNode(-1, head);
        ListNode* prev = dummy;
        for (int i = 0; i < n / k; ++i) {
            curr = prev->next;
            for (int j = 0; j < k - 1; ++j) {
                ListNode* tmp = curr->next;
                curr->next = tmp->next;
                tmp->next = prev->next;
                prev->next = tmp;
            }
            prev = curr;
        }
        return dummy->next;
    }
};
