class Solution:
    def numEquivDominoPairs(self, dominoes):
        freq = {}
        ans = 0

        for a, b in dominoes:
            key = (min(a, b), max(a, b))

            ans += freq.get(key, 0)

            freq[key] = freq.get(key, 0) + 1

        return ans