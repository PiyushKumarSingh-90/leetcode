class Solution:
    def distributeCandies(self, candyType):
        unique = len(set(candyType))
        allowed = len(candyType) // 2

        return min(unique, allowed)