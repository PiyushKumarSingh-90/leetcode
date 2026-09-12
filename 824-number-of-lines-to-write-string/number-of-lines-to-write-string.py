class Solution:
    def numberOfLines(self, widths, s):
        lines = 1
        current = 0

        for ch in s:
            width = widths[ord(ch) - ord('a')]

            current += width

            if current > 100:
                lines += 1
                current = width

        return [lines, current]