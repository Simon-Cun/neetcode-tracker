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
        ListNode* curr = head;
        int n = 0;
        while(curr) {
            ++n;
            curr = curr->next;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* half = nullptr;
        while (slow) {
            ListNode* tmp = slow;
            slow = slow->next;
            tmp->next = half;
            half = tmp;
            cout << half->val;
        }
        ListNode* ret = head;
        ListNode* tail = head;
        head = head->next;
        
        int count = 0;
        while (count != n && half) {
            if (count % 2 == 0) {
                tail->next = half;
                half = half->next;
            } else {
                tail->next = head;
                head = head->next;
            }
            tail = tail->next;
            ++count;
        }
        head = ret;
        tail->next = nullptr;
    }
};
