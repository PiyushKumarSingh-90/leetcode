class Solution:
    def maxCount(self, m: int, n: int, ops):
        minRow = m
        minCol = n

        for a, b in ops:
            minRow = min(minRow, a)
            minCol = min(minCol, b)

        return minRow * minCol