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
        if (!head) return nullptr;
        unordered_map<int, ListNode*> hashMap;
        int count = 0;
        while (head) {
            hashMap[count] = head;
            ++count;
            head = head->next;
        }
        int n = count - (count % k);
        ListNode* ret = new ListNode(-1);
        ListNode* tail = ret;
        for (int i = 0; i < n; i += k) {
            cout << "i: " << i << endl;
            for (int j = i + k - 1; j >= i; --j) {
                cout << "j: " << j << endl;
                tail->next = hashMap[j];
                tail = tail->next;
            }
        }
        for (int i = n; i < count; ++i) {
            tail->next = hashMap[i];
            tail = tail->next;
        }
        tail->next = nullptr;
        ListNode* temp = ret;
        ret = ret->next;
        delete temp;
        return ret;
    }
};
