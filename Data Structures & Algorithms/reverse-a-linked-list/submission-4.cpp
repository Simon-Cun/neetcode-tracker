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
    ListNode* reverseList(ListNode* head) {
        ListNode* ret = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* tmp = curr;
            curr = curr->next;
            tmp->next = ret;
            ret = tmp;
        }
        return ret;
    }
};
