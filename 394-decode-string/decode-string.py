class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        current = ""
        num = 0

        for ch in s:

            if ch.isdigit():
                num = num * 10 + int(ch)

            elif ch == '[':
                stack.append((current, num))

                current = ""
                num = 0

            elif ch == ']':
                previous, repeat = stack.pop()

                current = previous + current * repeat

            else:
                current += ch

        return current