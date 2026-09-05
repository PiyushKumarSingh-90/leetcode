class Solution:
    def canReach(self, start, target):
        startColor = (start[0] + start[1]) % 2
        targetColor = (target[0] + target[1]) % 2

        return startColor == targetColor