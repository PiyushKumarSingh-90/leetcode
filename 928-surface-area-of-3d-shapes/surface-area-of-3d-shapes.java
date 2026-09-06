class Solution {
    public int surfaceArea(int[][] grid) {

        int n = grid.length;
        int area = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                int value = grid[i][j];

                if (value > 0) {

                    area += value * 6;

                    area -= 2 * (value - 1);

                    if (i > 0) {
                        area -= 2 * Math.min(
                            value,
                            grid[i - 1][j]
                        );
                    }

                    if (j > 0) {
                        area -= 2 * Math.min(
                            value,
                            grid[i][j - 1]
                        );
                    }
                }
            }
        }

        return area;
    }
}