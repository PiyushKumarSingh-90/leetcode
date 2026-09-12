class Solution:
    def largeGroupPositions(self, s):
        start = 0
        ans = []

        for i in range(1, len(s)):

            if s[i] != s[i - 1]:

                if i - start >= 3:
                    ans.append([start, i - 1])

                start = i

        if len(s) - start >= 3:
            ans.append([start, len(s) - 1])

        return ans