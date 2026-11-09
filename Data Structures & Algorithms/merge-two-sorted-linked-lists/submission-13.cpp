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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ret = nullptr;
        ListNode* tail = nullptr;
        while (list1 || list2) {
            ListNode* toAppend = nullptr;
            if (!list1 && !list2) {
                return ret;
            } else if (list1 && !list2) {
                toAppend = list1;
                list1 = list1->next;
            } else if (list2 && !list1) {
                toAppend = list2;
                list2 = list2->next;
            } else {
                if (list1->val < list2->val) {
                    toAppend = list1;
                    list1 = list1->next;
                } else {
                    toAppend = list2;
                    list2 = list2->next;
                }
            }
            if (!ret && !tail) {
                ret = toAppend;
                tail = toAppend;
            } else {
                tail->next = toAppend;
                tail = tail->next;
                tail->next = nullptr;
            }
        }
        return ret;
    }
};
