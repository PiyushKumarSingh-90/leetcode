import random

class Solution:

    def __init__(self, nums):
        self.nums = nums

    def reset(self):
        return self.nums

    def shuffle(self):
        arr = self.nums[:]

        for i in range(len(arr)):
            j = random.randint(0, len(arr) - 1)
            arr[i], arr[j] = arr[j], arr[i]

        return arr