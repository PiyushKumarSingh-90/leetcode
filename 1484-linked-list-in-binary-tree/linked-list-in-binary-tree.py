# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:

        def dfs(head, node):
            if not head:
                return True
            if not node:
                return False
            if head.val != node.val:
                return False

            return dfs(head.next, node.left) or dfs(head.next, node.right)

        if not root:
            return False

        return (
            dfs(head, root)
            or self.isSubPath(head, root.left)
            or self.isSubPath(head, root.right)
        )