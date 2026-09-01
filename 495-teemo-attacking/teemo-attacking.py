class Solution:
    def findPoisonedDuration(self, timeSeries, duration):
        total = duration

        for i in range(1, len(timeSeries)):
            gap = timeSeries[i] - timeSeries[i - 1]

            total += min(gap, duration)

        return total