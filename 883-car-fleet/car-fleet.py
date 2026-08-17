class Solution:
    def carFleet(self, target, position, speed):
        cars = list(zip(position, speed))

        # Closest car to target first
        cars.sort(reverse=True)

        stack = []

        for pos, spd in cars:
            time = (target - pos) / spd

            # Car cannot catch the fleet ahead
            # so it becomes a new fleet
            if not stack or time > stack[-1]:
                stack.append(time)

        return len(stack)