class Solution:
    def maximalRectangle(self, matrix):

        if not matrix:
            return 0

        cols = len(matrix[0])
        heights = [0] * (cols + 1)

        ans = 0

        for row in matrix:

            # Build histogram
            for i in range(cols):
                if row[i] == "1":
                    heights[i] += 1
                else:
                    heights[i] = 0

            stack = []

            for i in range(cols + 1):

                while stack and heights[stack[-1]] > heights[i]:

                    h = heights[stack.pop()]

                    if stack:
                        width = i - stack[-1] - 1
                    else:
                        width = i

                    ans = max(ans, h * width)

                stack.append(i)

        return ans