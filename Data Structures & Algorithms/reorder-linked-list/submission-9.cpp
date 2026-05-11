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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow->next;
        slow->next = nullptr;
        slow = nullptr;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = slow;
            slow = curr;
            curr = temp;
        }
        curr = head;
        ListNode* tail = curr;
        curr = curr->next;
        while (slow or curr) {
            if (slow) {
                tail->next = slow;
                tail = tail->next;
                slow = slow->next;
            }
            if (curr) {
                tail->next = curr;
                tail = tail->next;
                curr = curr->next;
            }
        }
        tail->next = nullptr;
    }
};
