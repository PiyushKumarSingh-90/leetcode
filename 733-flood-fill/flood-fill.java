class Solution {

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {

        int old = image[sr][sc];

        if (old == color) {
            return image;
        }

        dfs(image, sr, sc, old, color);

        return image;
    }

    private void dfs(
        int[][] image,
        int r,
        int c,
        int old,
        int color
    ) {
        int rows = image.length;
        int cols = image[0].length;

        if (
            r < 0 ||
            r >= rows ||
            c < 0 ||
            c >= cols
        ) {
            return;
        }

        if (image[r][c] != old) {
            return;
        }

        image[r][c] = color;

        dfs(image, r + 1, c, old, color);
        dfs(image, r - 1, c, old, color);
        dfs(image, r, c + 1, old, color);
        dfs(image, r, c - 1, old, color);
    }
}