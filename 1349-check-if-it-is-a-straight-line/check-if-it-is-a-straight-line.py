class Solution:
    def checkStraightLine(self, coordinates):
        x1, y1 = coordinates[0]
        x2, y2 = coordinates[1]

        dx = x2 - x1
        dy = y2 - y1

        for i in range(2, len(coordinates)):
            x, y = coordinates[i]

            if (y - y1) * dx != (x - x1) * dy:
                return False

        return True