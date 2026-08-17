class Solution:
    def maxChunksToSorted(self, arr):
        maximum = 0
        chunks = 0

        for i in range(len(arr)):

            maximum = max(maximum, arr[i])

            if maximum == i:
                chunks += 1

        return chunks