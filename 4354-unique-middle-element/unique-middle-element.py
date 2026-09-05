class Solution:
    def isMiddleElementUnique(self, nums):
        mid = len(nums) // 2
        target = nums[mid]

        count = 0

        for num in nums:
            if num == target:
                count += 1

                if count > 1:
                    return False

        return True