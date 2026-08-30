class Solution:
    def solveSudoku(self, board):
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]

        empty = []

        # Store existing numbers
        for r in range(9):
            for c in range(9):
                if board[r][c] == ".":
                    empty.append((r, c))
                else:
                    num = board[r][c]

                    rows[r].add(num)
                    cols[c].add(num)

                    box = (r // 3) * 3 + (c // 3)
                    boxes[box].add(num)

        digits = set("123456789")

        def backtrack(index):

            if index == len(empty):
                return True

            # Find the cell having minimum possible choices
            best = index
            best_options = None

            for i in range(index, len(empty)):
                r, c = empty[i]

                box = (r // 3) * 3 + (c // 3)

                options = (
                    digits
                    - rows[r]
                    - cols[c]
                    - boxes[box]
                )

                if best_options is None or len(options) < len(best_options):
                    best = i
                    best_options = options

                if len(best_options) == 1:
                    break

            # No possible number
            if not best_options:
                return False

            # Put best cell at current index
            empty[index], empty[best] = empty[best], empty[index]

            r, c = empty[index]
            box = (r // 3) * 3 + (c // 3)

            for num in best_options:

                board[r][c] = num

                rows[r].add(num)
                cols[c].add(num)
                boxes[box].add(num)

                if backtrack(index + 1):
                    return True

                board[r][c] = "."

                rows[r].remove(num)
                cols[c].remove(num)
                boxes[box].remove(num)

            # Restore order
            empty[index], empty[best] = empty[best], empty[index]

            return False

        backtrack(0)