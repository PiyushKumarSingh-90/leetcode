class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:

        n = len(s)

        for length in range(1, n):

            if n % length != 0:
                continue

            part = s[:length]

            repeat = n // length

            if part * repeat == s:
                return True

        return False