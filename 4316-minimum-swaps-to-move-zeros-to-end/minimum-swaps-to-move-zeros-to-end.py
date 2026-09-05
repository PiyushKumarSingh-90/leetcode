class Solution:
    def minimumSwaps(self, nums):
        zeros = nums.count(0)
        nonZeros = len(nums) - zeros

        swaps = 0

        for i in range(nonZeros):
            if nums[i] == 0:
                swaps += 1

        return swaps