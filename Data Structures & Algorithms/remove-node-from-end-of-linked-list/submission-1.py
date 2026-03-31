# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        temp = head
        count = 0
        while head:
            head = head.next
            count += 1
        head = temp
        prev = None
        for i in range(count - n):
            prev = head
            head = head.next
        if not prev:
            return temp.next
        else:
            prev.next = head.next
            return temp