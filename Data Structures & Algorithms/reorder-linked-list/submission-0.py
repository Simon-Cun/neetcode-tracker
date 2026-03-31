# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        def recursion(root: ListNode, curr : ListNode) -> ListNode:
            if not curr:
                return root
            
            root = recursion(root, curr.next)
            if not root:
                return None

            tmp = None
            if root == curr or root.next == curr:
                curr.next = None
            else:
                tmp = root.next
                root.next = curr
                curr.next = tmp

            return tmp

        head = recursion(head, head.next)