class Solution:
    def increasingBST(self, root):
        stack = []
        curr = root

        dummy = TreeNode(0)
        tail = dummy

        while curr or stack:

            while curr:
                stack.append(curr)
                curr = curr.left

            curr = stack.pop()

            right = curr.right

            curr.left = None

            tail.right = curr
            tail = curr

            curr = right

        return dummy.right