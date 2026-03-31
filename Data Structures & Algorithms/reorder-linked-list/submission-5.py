# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if head.next == None:
            return
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        curr = slow.next
        slow.next = None
        reversed_list = None
        while curr:
            temp = curr.next
            curr.next = reversed_list
            reversed_list = curr
            curr = temp
        begin = head
        res = begin
        begin = begin.next
        res.next = reversed_list
        reversed_list = reversed_list.next
        curr = res.next
        while begin and reversed_list:
            print(begin.val, reversed_list.val)
            if begin:
                curr.next = begin
                curr = curr.next
                begin = begin.next
            if reversed_list:
                curr.next = reversed_list
                curr = curr.next
                reversed_list = reversed_list.next
        if reversed_list:
            curr.next = reversed_list
            curr = curr.next
        if begin:
            curr.next = begin
            curr = curr.next
        curr.next = None
        return None

