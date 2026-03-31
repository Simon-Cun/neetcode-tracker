# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        l = []
        curr = head
        count = 0
        while curr:
            count += 1
            curr = curr.next
        m = count // k
        for i in range(m):
            temp = None
            for j in range(k):
                tmp = head
                head = head.next
                tmp.next = temp
                temp = tmp
            l.append(temp)
        l.append(head)
        prev = None
        for i in l:
            if prev:
                prev.next = i
            if not i:
                break
            while i.next:
                i = i.next
            prev = i
        return l[0]