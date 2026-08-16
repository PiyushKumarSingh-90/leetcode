class Solution:
    def postorder(self, root):
        if not root:
            return []

        stack = [root]
        ans = []

        while stack:
            node = stack.pop()

            ans.append(node.val)

            for child in node.children:
                stack.append(child)

        ans.reverse()

        return ans