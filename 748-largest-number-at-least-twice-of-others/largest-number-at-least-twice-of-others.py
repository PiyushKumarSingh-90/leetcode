class Solution:
    def dominantIndex(self, nums):
        largest = -1
        second = -1
        index = -1

        for i in range(len(nums)):

            if nums[i] > largest:
                second = largest
                largest = nums[i]
                index = i

            elif nums[i] > second:
                second = nums[i]

        if largest >= 2 * second:
            return index

        return -1