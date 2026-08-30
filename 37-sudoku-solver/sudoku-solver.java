import java.util.*;

class Solution {

    private char[][] board;

    private boolean[][] rows = new boolean[9][10];
    private boolean[][] cols = new boolean[9][10];
    private boolean[][] boxes = new boolean[9][10];

    private List<int[]> empty = new ArrayList<>();

    public void solveSudoku(char[][] board) {

        this.board = board;

        for (int r = 0; r < 9; r++) {

            for (int c = 0; c < 9; c++) {

                if (board[r][c] == '.') {
                    empty.add(new int[]{r, c});
                }
                else {

                    int num = board[r][c] - '0';

                    rows[r][num] = true;
                    cols[c][num] = true;

                    int box = (r / 3) * 3 + c / 3;

                    boxes[box][num] = true;
                }
            }
        }

        backtrack(0);
    }

    private boolean backtrack(int index) {

        if (index == empty.size()) {
            return true;
        }

        int best = index;
        int minimum = 10;

        for (int i = index; i < empty.size(); i++) {

            int r = empty.get(i)[0];
            int c = empty.get(i)[1];

            int box = (r / 3) * 3 + c / 3;

            int count = 0;

            for (int num = 1; num <= 9; num++) {

                if (
                    !rows[r][num] &&
                    !cols[c][num] &&
                    !boxes[box][num]
                ) {
                    count++;
                }
            }

            if (count < minimum) {
                minimum = count;
                best = i;
            }

            if (minimum == 1) {
                break;
            }
        }

        if (minimum == 0) {
            return false;
        }

        Collections.swap(empty, index, best);

        int r = empty.get(index)[0];
        int c = empty.get(index)[1];

        int box = (r / 3) * 3 + c / 3;

        for (int num = 1; num <= 9; num++) {

            if (
                !rows[r][num] &&
                !cols[c][num] &&
                !boxes[box][num]
            ) {

                board[r][c] = (char) ('0' + num);

                rows[r][num] = true;
                cols[c][num] = true;
                boxes[box][num] = true;

                if (backtrack(index + 1)) {
                    return true;
                }

                board[r][c] = '.';

                rows[r][num] = false;
                cols[c][num] = false;
                boxes[box][num] = false;
            }
        }

        Collections.swap(empty, index, best);

        return false;
    }
}