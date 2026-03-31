# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        dictionary = {}
        for i in lists:
            while i:
                dictionary[i] = i.val
                i = i.next
        if not dictionary:
            return None
        minNode = min(dictionary, key=dictionary.get)
        head = minNode
        del dictionary[minNode]
        curr = head
        while dictionary:
            minNode = min(dictionary, key=dictionary.get)
            curr.next = minNode
            del dictionary[minNode]
            curr = curr.next
        return head