class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        ans = 0

        for ch in columnTitle:
            value = ord(ch) - ord('A') + 1

            ans = ans * 26 + value

        return ans