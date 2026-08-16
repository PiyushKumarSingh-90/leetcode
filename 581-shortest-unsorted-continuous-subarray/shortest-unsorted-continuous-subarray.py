class Solution:
    def findUnsortedSubarray(self, nums):
        n = len(nums)

        stack = []
        left = n
        right = 0

        # Find left boundary
        for i in range(n):

            while stack and nums[stack[-1]] > nums[i]:
                left = min(left, stack.pop())

            stack.append(i)

        stack = []

        # Find right boundary
        for i in range(n - 1, -1, -1):

            while stack and nums[stack[-1]] < nums[i]:
                right = max(right, stack.pop())

            stack.append(i)

        if left == n:
            return 0

        return right - left + 1