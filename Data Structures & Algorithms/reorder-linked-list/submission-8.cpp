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
        unordered_map<int, ListNode*> hashMap;
        ListNode* curr = head;
        int count = 0;
        while (curr) {
            hashMap[count] = curr;
            curr = curr->next;
            ++count;
        }
        ListNode* tail = head;
        int l = 1, r = count - 1;
        while (l <= r) {
            tail->next = hashMap[r--];
            tail = tail->next;
            if (l > r) break;
            tail->next = hashMap[l++];
            tail = tail->next;
        }
        tail->next = nullptr;
    }
};
