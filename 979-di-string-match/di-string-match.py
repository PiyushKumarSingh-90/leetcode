class Solution:
    def diStringMatch(self, s):
        low = 0
        high = len(s)

        ans = []

        for ch in s:

            if ch == "I":
                ans.append(low)
                low += 1

            else:
                ans.append(high)
                high -= 1

        ans.append(low)

        return ans