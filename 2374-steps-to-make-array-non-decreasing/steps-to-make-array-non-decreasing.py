class Solution:
    def totalSteps(self, nums):
        stack = []
        ans = 0

        for num in nums:
            steps = 0

            while stack and num >= stack[-1][0]:
                steps = max(steps, stack[-1][1])
                stack.pop()

            if stack:
                steps += 1
            else:
                steps = 0

            ans = max(ans, steps)
            stack.append((num, steps))

        return ans
        