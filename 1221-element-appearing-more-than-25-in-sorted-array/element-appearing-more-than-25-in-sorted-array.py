class Solution:
    def findSpecialInteger(self, arr):
        count = 1
        limit = len(arr) // 4

        if len(arr) == 1:
            return arr[0]

        for i in range(1, len(arr)):

            if arr[i] == arr[i - 1]:
                count += 1
            else:
                count = 1

            if count > limit:
                return arr[i]

        return arr[0]