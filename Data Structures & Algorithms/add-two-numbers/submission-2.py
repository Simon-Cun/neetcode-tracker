# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        count = 0
        num1 = 0
        num2 = 0
        while l1:
            num1 += l1.val * (10 ** count)
            l1 = l1.next
            count += 1
        count = 0 
        while l2:
            num2 += l2.val * (10 ** count)
            l2 = l2.next
            count += 1
        final_sum = num1 + num2
        print(final_sum)
        rev = list(str(final_sum))

        l3 = ListNode(int(rev.pop()))
        head = l3
        while len(rev) != 0:
            l3.next = ListNode(int(rev.pop()))
            l3 = l3.next
        return head
        
            

            
        return None