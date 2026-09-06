class Solution:
    def surfaceArea(self, grid):
        n = len(grid)
        area = 0

        for i in range(n):
            for j in range(n):

                value = grid[i][j]

                if value > 0:
                    area += value * 6

                    area -= 2 * (value - 1)

                    if i > 0:
                        area -= 2 * min(
                            value,
                            grid[i - 1][j]
                        )

                    if j > 0:
                        area -= 2 * min(
                            value,
                            grid[i][j - 1]
                        )

        return area