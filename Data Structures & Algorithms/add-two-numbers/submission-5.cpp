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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = nullptr;
        ListNode* tail = nullptr;
        int rem = 0;
        while (l1 || l2 || rem != 0) {
            int sum = 0;
            if (l1 && l2) {
                sum = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1) {
                sum = l1->val;
                l1 = l1->next;
            } else if (l2) {
                sum = l2->val;
                l2 = l2->next;
            }
            sum += rem;
            rem = sum / 10;
            if (sum >= 10) sum -= 10;
            if (!ret && !tail) {
                ret = new ListNode(sum);
                tail = ret;
            } else {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
            
        }
        return ret;
    }
};
