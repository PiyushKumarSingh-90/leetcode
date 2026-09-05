class Solution:
    def elevatorRequests(self, n, requests):
        total = 0
        current = 0

        for floor in requests:
            total += abs(floor - current)
            current = floor

        return total