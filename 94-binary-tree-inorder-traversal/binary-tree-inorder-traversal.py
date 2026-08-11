# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root):
        stack = []
        ans = []

        curr = root

        while curr or stack:

            # Go to leftmost node
            while curr:
                stack.append(curr)
                curr = curr.left

            # Process node
            curr = stack.pop()
            ans.append(curr.val)

            # Go to right subtree
            curr = curr.right

        return ans
        