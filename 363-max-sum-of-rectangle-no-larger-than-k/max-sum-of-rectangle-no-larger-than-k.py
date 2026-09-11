from bisect import bisect_left, insort

class Solution:
    def maxSumSubmatrix(self, matrix, k):
        if len(matrix) > len(matrix[0]):
            matrix = list(map(list, zip(*matrix)))

        rows = len(matrix)
        cols = len(matrix[0])

        ans = float("-inf")

        for top in range(rows):
            sums = [0] * cols

            for bottom in range(top, rows):

                for c in range(cols):
                    sums[c] += matrix[bottom][c]

                prefix = 0
                prefixes = [0]

                for num in sums:
                    prefix += num

                    index = bisect_left(
                        prefixes,
                        prefix - k
                    )

                    if index < len(prefixes):
                        ans = max(
                            ans,
                            prefix - prefixes[index]
                        )

                    if ans == k:
                        return k

                    insort(prefixes, prefix)

        return ans