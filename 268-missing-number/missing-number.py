class Solution:
    def missingNumber(self, nums):
        values = set(nums)

        for i in range(len(nums) + 1):
            if i not in values:
                return i