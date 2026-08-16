class Solution:
    def nextGreaterElements(self, nums):
        n = len(nums)
        ans = [-1] * n
        stack = []

        for i in range(2 * n):

            index = i % n

            while stack and nums[stack[-1]] < nums[index]:
                old = stack.pop()
                ans[old] = nums[index]

            stack.append(index)

        return ans