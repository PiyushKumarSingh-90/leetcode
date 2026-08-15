class Solution:
    def deserialize(self, s: str) -> NestedInteger:

        # Single integer
        if s[0] != '[':
            return NestedInteger(int(s))

        stack = []

        num = 0
        sign = 1
        has_num = False

        for ch in s:

            if ch == '[':
                stack.append(NestedInteger())

            elif ch == '-':
                sign = -1

            elif ch.isdigit():
                num = num * 10 + int(ch)
                has_num = True

            elif ch == ',':

                if has_num:
                    stack[-1].add(
                        NestedInteger(sign * num)
                    )

                num = 0
                sign = 1
                has_num = False

            elif ch == ']':

                if has_num:
                    stack[-1].add(
                        NestedInteger(sign * num)
                    )

                num = 0
                sign = 1
                has_num = False

                completed = stack.pop()

                if stack:
                    stack[-1].add(completed)
                else:
                    return completed