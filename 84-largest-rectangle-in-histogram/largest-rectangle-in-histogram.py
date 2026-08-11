class Solution:
    def largestRectangleArea(self, heights):

        heights.append(0)

        stack = []
        ans = 0

        for i in range(len(heights)):

            while stack and heights[stack[-1]] > heights[i]:

                h = heights[stack.pop()]

                if stack:
                    width = i - stack[-1] - 1
                else:
                    width = i

                ans = max(ans, h * width)

            stack.append(i)

        return ans