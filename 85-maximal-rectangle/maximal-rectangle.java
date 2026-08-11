import java.util.*;

class Solution {
    public int maximalRectangle(char[][] matrix) {

        int rows = matrix.length;
        int cols = matrix[0].length;

        int[] heights = new int[cols + 1];

        int ans = 0;

        for (int r = 0; r < rows; r++) {

            // Build histogram
            for (int c = 0; c < cols; c++) {

                if (matrix[r][c] == '1') {
                    heights[c]++;
                } else {
                    heights[c] = 0;
                }
            }

            Stack<Integer> stack = new Stack<>();

            for (int i = 0; i <= cols; i++) {

                while (!stack.isEmpty() &&
                       heights[stack.peek()] > heights[i]) {

                    int h = heights[stack.pop()];

                    int width;

                    if (stack.isEmpty()) {
                        width = i;
                    } else {
                        width = i - stack.peek() - 1;
                    }

                    ans = Math.max(ans, h * width);
                }

                stack.push(i);
            }
        }

        return ans;
    }
}