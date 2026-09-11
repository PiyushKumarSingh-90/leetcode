class Solution:
    def wiggleMaxLength(self, nums):
        count = 1
        prevDiff = 0

        for i in range(1, len(nums)):
            diff = nums[i] - nums[i - 1]

            if diff > 0 and prevDiff <= 0:
                count += 1
                prevDiff = diff

            elif diff < 0 and prevDiff >= 0:
                count += 1
                prevDiff = diff

        return count