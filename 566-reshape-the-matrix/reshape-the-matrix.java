class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {

        int m = mat.length;
        int n = mat[0].length;

        if (m * n != r * c) {
            return mat;
        }

        int[][] ans = new int[r][c];

        int index = 0;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                int newRow = index / c;
                int newCol = index % c;

                ans[newRow][newCol] = mat[i][j];

                index++;
            }
        }

        return ans;
    }
}