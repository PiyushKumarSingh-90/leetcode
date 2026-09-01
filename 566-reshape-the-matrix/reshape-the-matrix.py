class Solution:
    def matrixReshape(self, mat, r, c):
        m = len(mat)
        n = len(mat[0])

        if m * n != r * c:
            return mat

        ans = [[0] * c for _ in range(r)]

        index = 0

        for i in range(m):
            for j in range(n):

                newRow = index // c
                newCol = index % c

                ans[newRow][newCol] = mat[i][j]

                index += 1

        return ans