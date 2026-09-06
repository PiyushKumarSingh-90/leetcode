class Solution:
    def numEquivDominoPairs(self, dominoes):
        freq = {}
        ans = 0

        for a, b in dominoes:

            if a > b:
                key = (a, b)
            else:
                key = (b, a)

            ans += freq.get(key, 0)
            freq[key] = freq.get(key, 0) + 1

        return ans