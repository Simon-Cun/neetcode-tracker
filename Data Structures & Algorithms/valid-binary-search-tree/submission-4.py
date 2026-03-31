# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        l = []
        def dfs(curr):
            if not curr:
                return
            dfs(curr.left)
            l.append(curr.val)
            dfs(curr.right)
        dfs(root)
        for i in range(len(l) - 1):
            if l[i] >= l[i + 1]:
                return False
        return True


        