class Solution:
    def generate(self, numRows: int):
        ans = [[1]]

        for i in range(1, numRows):

            prev = ans[i - 1]
            row = [1]

            for j in range(len(prev) - 1):
                row.append(prev[j] + prev[j + 1])

            row.append(1)

            ans.append(row)

        return ans