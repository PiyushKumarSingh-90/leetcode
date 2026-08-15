class Solution:
    def find132pattern(self, nums):
        stack = []
        second = float('-inf')

        for num in reversed(nums):

            # num = possible "1"
            if num < second:
                return True

            # num = possible "3"
            while stack and stack[-1] < num:
                second = stack.pop()

            stack.append(num)

        return False