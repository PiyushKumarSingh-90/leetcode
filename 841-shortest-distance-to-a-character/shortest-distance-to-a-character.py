class Solution:
    def shortestToChar(self, s, c):
        n = len(s)
        ans = [n] * n

        prev = -n

        for i in range(n):
            if s[i] == c:
                prev = i

            ans[i] = i - prev

        prev = n * 2

        for i in range(n - 1, -1, -1):
            if s[i] == c:
                prev = i

            ans[i] = min(ans[i], prev - i)

        return ans