class Solution:
    def maxDepth(self, s: str) -> int:
        depth = 0
        maximum = 0

        for ch in s:

            if ch == '(':
                depth += 1
                maximum = max(maximum, depth)

            elif ch == ')':
                depth -= 1

        return maximum